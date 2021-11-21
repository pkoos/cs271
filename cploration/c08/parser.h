#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_LINE_LENGTH 200
#define MAX_LABEL_LENGTH (MAX_LINE_LENGTH - 2)

typedef int16_t hack_addr;
typedef int16_t opcode;
typedef struct c_instruction {
    opcode a:1;
    opcode comp:6;
    opcode dest:3;
    opcode jump:3;
} c_instruction;

typedef struct a_instruction {
    union address {
        hack_addr address;
        char * label;
    } address;
    bool is_addr;
} a_instruction;

typedef struct instruction {
    union instr_type {
        a_instruction a_inst;
        c_instruction c_inst;
    } instr_type;
} instruction ;

enum instruction_type {
    invalid = -1,
    a_type,
    c_type
};

char *strip(char *);
void parse(FILE *);
bool is_Atype(const char *);
bool is_label(const char *);
bool is_Ctype(const char *);
char *extract_label(const char *, char *);