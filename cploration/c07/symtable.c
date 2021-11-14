#include "symtable.h"

int hash(char *str) {
    unsigned int hash = 5381;
    int c;

    while( (c = *str++) ) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

void insert(char *key, hack_addr value) {
    Symbol *item = (Symbol*) malloc(sizeof(Symbol));
    item->value = value;
    item->key = key;

    int hashIndex = hash(key);

    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != NULL) {
        ++hashIndex;

        hashIndex %= SYMBOL_TABLE_SIZE;
    }

    hashArray[hashIndex] = item;
}