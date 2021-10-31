#include "parser.h"

void parse(FILE * file) {
    char line[MAX_LINE_LENGTH] = {0};
    

    while(fgets(line, sizeof(line), file)) {
        char inst_type = ' ';
        strip(line);
        if(!*line) { continue; }
        if(is_Atype(line)) {
            inst_type = 'A';
        } else if(is_label(line)) {
            inst_type = 'L';
        }
        printf("%c  %s\n",inst_type, line);
    }
}

char *strip(char *s) {
    char s_new[strlen(s) + 1];
    int i = 0;
    
    for(char *s2 = s; *s2; s2++) {
        if(*s == '/' && *(s+1) == '/') { 
            break;
        } else if(!isspace(*s2)) {
            s_new[i++] = *s2;
        }
    }
    s_new[i] = '\0';
    strcpy(s, s_new);
    
    return s;
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
