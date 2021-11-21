#ifndef __ERROR_H__
#define __ERROR_H__

#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>

enum exitcode {
    EXIT_INCORRECT_ARGUMENTS = 1,
    EXIT_CANNOT_OPEN_FILE,
    EXIT_TOO_MANY_INSTRUCTIONS, 
    EXIT_INVALID_LABEL,
    EXIT_SYMBOL_ALREADY_EXISTS,
};

void exit_program(enum exitcode, ...);

#endif
