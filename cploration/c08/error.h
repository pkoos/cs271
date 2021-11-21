#ifndef __ERROR_H__
#define __ERROR_H__

#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>

enum exitcode {
    EXIT_INCORRECT_ARGUMENTS = 1,
    EXIT_CANNOT_OPEN_FILE,
};

void exit_program(enum exitcode, ...);

#endif
