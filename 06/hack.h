#ifndef __HACK_H__
#define __HACK_H__

#include <stdint.h>
#include <string.h>

#define NUM_PREDEFINED_SYMBOLS 23

#define OPCODE_TO_BINARY(opcode) \
  (opcode & 0x8000 ? '1' : '0'), \
  (opcode & 0x4000 ? '1' : '0'), \
  (opcode & 0x2000 ? '1' : '0'), \
  (opcode & 0x1000 ? '1' : '0'), \
  (opcode & 0x800 ? '1' : '0'), \
  (opcode & 0x400 ? '1' : '0'), \
  (opcode & 0x200 ? '1' : '0'), \
  (opcode & 0x100 ? '1' : '0'), \
  (opcode & 0x80 ? '1' : '0'), \
  (opcode & 0x40 ? '1' : '0'), \
  (opcode & 0x20 ? '1' : '0'), \
  (opcode & 0x10 ? '1' : '0'), \
  (opcode & 0x8 ? '1' : '0'), \
  (opcode & 0x4 ? '1' : '0'), \
  (opcode & 0x2 ? '1' : '0'), \
  (opcode & 0x1 ? '1' : '0')

typedef enum symbol_id {
    SYM_RO = 0,
    SYM_R1, 
    SYM_R2,
    SYM_R3,
    SYM_R4,
    SYM_R5,
    SYM_R6,
    SYM_R7,
    SYM_R8,
    SYM_R9,
    SYM_R10,
    SYM_R11,
    SYM_R12,
    SYM_R13,
    SYM_R14,
    SYM_R15,
    SYM_SP = 0,
    SYM_LCL,
    SYM_ARG,
    SYM_THIS,
    SYM_THAT,
    SYM_SCREEN = 16384,
    SYM_KBD = 24576
} symbol_id;

typedef enum jump_id {
    JMP_INVALID = -1,
    JMP_NULL,
    JMP_JGT,
    JMP_JEQ,
    JMP_JGE,
    JMP_JLT,
    JMP_JNE,
    JMP_JLE,
    JMP_JMP
} jump_id;

typedef enum dest_id {
    DEST_INVALID = -1,
    DEST_NULL,
    DEST_M,
    DEST_D,
    DEST_DM,
    DEST_A,
    DEST_AM,
    DEST_AD,
    DEST_ADM
} dest_id;

typedef enum comp_id {
    COMP_INVALID = -1,
    COMP_0 = 42,
    COMP_1 = 63,
    COMP_NEG_1 = 58,
    COMP_D = 12,
    COMP_A = 48,
    COMP_M = 48,
    COMP_NOT_D = 13,
    COMP_NOT_A = 49,
    COMP_NOT_M = 49,
    COMP_NEG_D = 15,
    COMP_NEG_A = 51,
    COMP_NEG_M = 51,
    COMP_D_PLUS_1 = 31,
    COMP_A_PLUS_1 = 55,
    COMP_M_PLUS_1 = 55,
    COMP_D_MINUS_1 = 14,
    COMP_A_MINUS_1 = 50,
    COMP_M_MINUS_1 = 50,
    COMP_D_PLUS_A = 2,
    COMP_D_PLUS_M = 2,
    COMP_D_MINUS_A = 19,
    COMP_D_MINUS_M = 19,
    COMP_A_MINUS_D = 7,
    COMP_M_MINUS_D = 7,
    COMP_D_AND_A = 0,
    COMP_D_AND_M = 0,
    COMP_D_BIN_OR_A = 21,
    COMP_D_BIN_OR_M = 21
} comp_id;

typedef struct predefined_symbol {
    char name[10];
    int16_t address;
} predefined_symbol;

static const predefined_symbol predefined_symbols[NUM_PREDEFINED_SYMBOLS] = {
    {{"R0"}, SYM_RO},
    {{"R1"}, SYM_R1},
    {{"R2"}, SYM_R2},
    {{"R3"}, SYM_R3},
    {{"R4"}, SYM_R4},
    {{"R5"}, SYM_R5},
    {{"R6"}, SYM_R6},
    {{"R7"}, SYM_R7},
    {{"R8"}, SYM_R8},
    {{"R9"}, SYM_R9},
    {{"R10"}, SYM_R10},
    {{"R11"}, SYM_R11},
    {{"R12"}, SYM_R12},
    {{"R13"}, SYM_R13},
    {{"R14"}, SYM_R14},
    {{"R15"}, SYM_R15},
    {{"SP"}, SYM_SP},
    {{"LCL"}, SYM_LCL},
    {{"ARG"}, SYM_ARG},
    {{"THIS"}, SYM_THIS},
    {{"THAT"}, SYM_THAT},
    {{"SCREEN"}, SYM_SCREEN},
    {{"KBD"}, SYM_KBD}
};

static inline jump_id str_to_jumpid(const char *s) {

    jump_id id = JMP_INVALID;

    if(s == NULL) {
        id = JMP_NULL;
    }
    else if(strstr(s, "JGT") != NULL) {
        id = JMP_JGT;
    }
    else if(strstr(s, "JEQ") != NULL) {
        id = JMP_JEQ;
    }
    else if(strstr(s, "JGE") != NULL) {
        id = JMP_JGE;
    }
    else if(strstr(s, "JLT") != NULL) {
        id = JMP_JLT;
    }
    else if(strstr(s, "JNE") != NULL) {
        id = JMP_JNE;
    }
    else if(strstr(s, "JLE") != NULL) {
        id = JMP_JLE;
    }
    else if(strstr(s, "JMP") != NULL) {
        id = JMP_JMP;
    }
    return id;                       
}

static inline dest_id str_to_dest_id(const char *s) {

    dest_id id = DEST_INVALID;

    if(s == NULL) {
        id = DEST_NULL;
    }
    else if(strstr(s, "M") != NULL) {
        id = DEST_M;
    }
    else if(strstr(s, "D") != NULL) {
        id = DEST_D;
    }
    else if(strstr(s, "DM") != NULL) {
        id = DEST_DM;
    }
    else if(strstr(s, "A") != NULL) {
        id = DEST_A;
    }
    else if(strstr(s, "AM") != NULL) {
        id = DEST_AM;
    }
    else if(strstr(s, "AD") != NULL) {
        id = DEST_AD;
    }
    else if(strstr(s, "ADM") != NULL) {
        id = DEST_ADM;
    }
    return id;
}

static inline comp_id str_to_compid(const char *s, int *a) {

    comp_id id = COMP_INVALID;
    *a = 0;

    if(strcmp(s, "0") == 0) {
        id = COMP_0;
    }
    else if(strcmp(s, "1") == 0) {
        id = COMP_1;
    }
    else if(strcmp(s, "-1") == 0) {
        id = COMP_NEG_1;
    }
    else if(strcmp(s, "D") == 0) {
        id = COMP_D;
    }
    else if(strcmp(s, "A") == 0) {
        id = COMP_A;
    }
    else if(strcmp(s, "M") == 0) {
        id = COMP_M;
        *a = 1;
    }
    else if(strcmp(s, "!D") == 0) {
        id = COMP_NOT_D;
    }
    else if(strcmp(s, "!A") == 0) {
        id = COMP_NOT_A;
    }
    else if(strcmp(s, "!M") == 0) {
        id = COMP_NOT_M;
        *a = 1;
    }
    else if(strcmp(s, "-D") == 0) {
        id = COMP_NEG_D;
    }
    else if(strcmp(s, "-A") == 0) {
        id = COMP_NEG_A;
    }
    else if(strcmp(s, "-M") == 0) {
        id = COMP_NEG_M;
        *a = 1;
    }
    else if(strcmp(s, "D+1") == 0) {
        id = COMP_D_PLUS_1;
    }
    else if(strcmp(s, "A+1") == 0) {
        id = COMP_A_PLUS_1;
    }
    else if(strcmp(s, "M+1") == 0) {
        id = COMP_M_PLUS_1;
        *a = 1;
    }
    else if(strcmp(s, "D-1") == 0) {
        id = COMP_D_MINUS_1;
    }
    else if(strcmp(s, "A-1") == 0) {
        id = COMP_A_MINUS_1;
    }
    else if(strcmp(s, "M-1") == 0) {
        id = COMP_M_MINUS_1;
        *a = 1;
    }
    else if(strcmp(s, "D+A") == 0) {
        id = COMP_D_PLUS_A;
    }
    else if(strcmp(s, "D+M") == 0) {
        id=COMP_D_PLUS_M;
        *a = 1;
    }
    else if(strcmp(s, "D-A") == 0) {
        id = COMP_D_MINUS_A;
    }
    else if(strcmp(s, "D-M") == 0) {
        id = COMP_D_MINUS_M;
        *a = 1;
    }
    else if(strcmp(s, "A-D") == 0) {
        id = COMP_A_MINUS_D;
    }
    else if(strcmp(s, "M-D") == 0) {
        id = COMP_M_MINUS_D;
        *a = 1;
    }
    else if(strcmp(s, "D&A") == 0) {
        id = COMP_D_AND_A;
    }
    else if(strcmp(s, "D&M") == 0) {
        id = COMP_D_AND_M;
        *a = 1;
    }
    else if(strcmp(s, "D|A") == 0) {
        id = COMP_D_BIN_OR_A;
    }
    else if(strcmp(s, "D|M") == 0) {
        id = COMP_D_BIN_OR_M;
        *a = 1;
    }
    return id;
}

#endif