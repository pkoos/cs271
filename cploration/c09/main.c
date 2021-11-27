#include "parser.h"
#include "error.h"

int main(int args, char *argv[]) {
    if(args != 2) {
        exit_program(EXIT_INCORRECT_ARGUMENTS, argv[0]);
    }

    FILE *fin = fopen(argv[1], "r");
    if(fin == NULL) {
        exit_program(EXIT_CANNOT_OPEN_FILE, argv[1]);
    }

    parse(fin);
    fclose(fin);
}