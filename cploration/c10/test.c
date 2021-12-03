#include "parser.h"
#include "error.h"

int main(int args, char *argv[]) {
    char test_string[45] = "A=D;JGE";
    char * dest;
    char * comp;
    char * jump;
    dest = strtok(test_string, "=");
    comp = strtok(NULL, ";");
    jump = strtok(NULL, "");
    printf("dest: %s, comp: %s, jump: %s\n", dest, comp, jump);

    return 0;
}