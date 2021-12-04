#include "parser.h"
#include "error.h"
#include "symtable.h"

void parse(FILE * file) {
    char line[MAX_LINE_LENGTH] = {0};
    unsigned int line_num = 0;
    unsigned int instr_num = 0;
    instruction instr;
    
    add_predefined_symbols();

    while(fgets(line, sizeof(line), file)) {
        line_num++;
        char inst_type = ' ';
        if(instr_num > MAX_INSTRUCTIONS) {
            exit_program(EXIT_TOO_MANY_INSTRUCTIONS, MAX_INSTRUCTIONS+1);
        }
        strip(line);
        if(!*line) { continue; }
        if(is_Atype(line)) {
            if(!parse_A_instruction(line, &instr.a_inst)) {
                exit_program(EXIT_INVALID_A_INSTR, line_num, line);
            }
            instr.inst_type = a_type;
            inst_type = 'A';
        } else if(is_label(line)) {
            char label[MAX_LABEL_LENGTH];
            extract_label(line, label);
            if(!isalpha(label[0])) {
                exit_program(EXIT_INVALID_LABEL, line_num, line);
            } else if(symtable_find(label)!= NULL) {
                exit_program(EXIT_SYMBOL_ALREADY_EXISTS, line_num, line);
            }
            strcpy(line, label);
            symtable_insert(label, instr_num);
            inst_type = 'L';
            continue;
        } else if(is_Ctype(line)) {
            char tmp_line[MAX_LINE_LENGTH];
            strcpy(tmp_line, line);
            parse_C_instruction(tmp_line, &instr.c_inst);
            if(instr.c_inst.dest == DEST_INVALID) {
                exit_program(EXIT_INVALID_C_DEST);
            }
            else if(instr.c_inst.comp == COMP_INVALID) {
                exit_program(EXIT_INVALID_C_COMP);
            }
            else if(instr.c_inst.jump == JMP_INVALID) {
                exit_program(EXIT_INVALID_C_JUMP);
            }
            instr.inst_type = c_type;
            inst_type = 'C';
        }
        printf("%c  %s\n",inst_type, line);
        instr_num++;
    }
}

char *strip(char *s) {
    char s_new[strlen(s) + 1];
    int i = 0;
    
    for(char *s2 = s; *s2; s2++) {
        if(*s2 == '/' && *(s2+1) == '/') { 
            break;
        } else if(!isspace(*s2)) {
            s_new[i++] = *s2;
        }
    }
    s_new[i] = '\0';
    strcpy(s, s_new);
    
    return s;
}

char *extract_label(const char* line, char * label) {    
    int i = 0;
    for(const char *s2 = line;*s2;s2++) {
        if(*s2 == '(' || *s2 == ')') {
            continue;
        } else {
            label[i++] = *s2;
        }
    }
    label[i] = '\0';

    return label;
}

bool is_Atype(const char *line) {
    return strncmp("@", line, 1) == 0;
}

bool is_label(const char *line) {
    if(line[0] != '(' && line[strlen(line) -1] != ')') {
        return false;
    } else {
        return true;
    }
}

bool is_Ctype(const char *line) {
    return !is_Atype(line) && !is_label(line);
}

void add_predefined_symbols() {
    for(int i = 0; i < NUM_PREDEFINED_SYMBOLS; i++) {
        symtable_insert(
            (char *) predefined_symbols[i].name, // cast const away
            predefined_symbols[i].address
            );
    }
}

bool parse_A_instruction(const char *line, a_instruction *instr) {
    
    char *s = (char*) malloc(strlen(line)+1);
    strcpy(s, line+1);
    
    char *s_end = NULL;
    long result = strtol(s, &s_end, 10);
    
    if(s == s_end) {
        instr->address.label = (char *) malloc(strlen(line)+1);
        strcpy(instr->address.label,s);
        instr->is_addr = false;
    }
    else if(*s_end != 0) {
        free(s);
        return false;
    }
    else {
        instr->address.address = result;
        instr->is_addr = true;
    }
    free(s);
    return true;
}

void parse_C_instruction(char *line, c_instruction *instr) {

    char delimiter[3] = "=;";
    char * line_copy = malloc(sizeof(line) * strlen(line) + 1);
    
    strcpy(line_copy, line);
    
    int i = 0;
    char * results[3];
    char * tok = strtok(line, delimiter);
    int a = 0;

    while (tok != NULL) {
        results[i++] = tok;
        tok = strtok(NULL, delimiter);
    }

    if(strchr(line_copy, ';') != NULL && strchr(line_copy, '=') != NULL) {
        // printf("dest=comp;jump\n");
        instr->dest = str_to_dest_id(results[0]);
        instr->comp = str_to_compid(results[1], &a);
        instr->a = a == 1 ? instr->a & 0x1: 0;

    }
    else if(strchr(line_copy, ';') != NULL) {
        // printf("comp;jump\n");
        instr->dest = 0;
        instr->comp = str_to_compid(results[0], &a);
        instr->jump = str_to_jumpid(results[1]);
        instr->a = a;
    }
    else if(strchr(line_copy, '=') != NULL) {
        // printf("dest=comp\n");
        instr->dest = str_to_dest_id(results[0]);
        instr->comp = str_to_compid(results[1], &a);
        instr->jump = 0;
        instr->a = a;
    }
    else {
        // printf("comp\n");
        instr->dest = 0;
        instr->comp = str_to_compid(results[0], &a);
        instr->jump = 0;
        instr->a = a == 1 ? instr->a & 0x1: 0;
    }
    free(line_copy);
}
