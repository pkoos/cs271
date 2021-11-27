#define NUM_PREDEFINED_SYMBOLS 23
#include <stdint.h>

typedef struct predefined_symbol {
    char * name;
    int16_t address;
} predefined_symbol;

enum predefined_symbols {
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
    SP = 0,
    LCL,
    ARG,
    THIS,
    THAT,
    SCREEN = 16384,
    KBD = 24576
};