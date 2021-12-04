#ifndef __PARSER_H__
#define __PARSER_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include "hack.h"

#define MAX_LINE_LENGTH 200
#define MAX_LABEL_LENGTH (MAX_LINE_LENGTH - 2)
#define MAX_HACK_ADDRESS INT16_MAX
#define MAX_INSTRUCTIONS MAX_HACK_ADDRESS

typedef int16_t hack_addr;
typedef int16_t opcode;
typedef struct c_instruction {
    opcode a:1;
    opcode comp:7;
    opcode dest:4;
    opcode jump:4;
} c_instruction;

typedef struct a_instruction {
    union address {
        hack_addr address;
        char * label;
    } address;
    bool is_addr;
} a_instruction;

typedef enum instruction_type {
    invalid = -1,
    a_type,
    c_type
} instruction_type;

typedef struct instruction {
    union {
        a_instruction a_inst;
        c_instruction c_inst;
    };
    instruction_type inst_type;
} instruction ;



char *strip(char *);
void parse(FILE *);
bool is_Atype(const char *);
bool is_label(const char *);
bool is_Ctype(const char *);
char *extract_label(const char *, char *);
void add_predefined_symbols();
bool parse_A_instruction(const char *, a_instruction *);
void parse_C_instruction(char *, c_instruction *);

#endif