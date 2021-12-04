#include "parser.h"
#include "error.h"

#define MAX_INSTRUCTION_COUNT 30000

int main(int args, char *argv[]) {
    if(args != 2) {
        exit_program(EXIT_INCORRECT_ARGUMENTS, argv[0]);
    }

    FILE *fin = fopen(argv[1], "r");
    if(fin == NULL) {
        exit_program(EXIT_CANNOT_OPEN_FILE, argv[1]);
    }

    instruction * instructions = malloc(MAX_INSTRUCTION_COUNT * sizeof(instruction));

    int num_instructions = parse(fin, instructions);
    fclose(fin);

    assemble(argv[1], instructions, num_instructions);

    printf("Number of instructions: %d\n", num_instructions);

    free(instructions);
    return 0;
}
