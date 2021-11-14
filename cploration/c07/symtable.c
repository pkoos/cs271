#include "symtable.h"

int hash(char *str) {
    unsigned int hash = 5381;
    int c;

    while( (c = *str++) ) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}