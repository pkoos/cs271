#include <parser.h>

int main(int args, char *argv[]) {
    if(args != 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fin = fopen(argv[1], "r");
    if(fin == NULL) {
        perror("Unable to open file!");
        exit(EXIT_FAILURE);
    }

    parse(fin);
    fclose(fin);
}