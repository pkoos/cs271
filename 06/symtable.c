#include "symtable.h"
#include <string.h>
int hash(char *str) {
    unsigned int hash = 5381;
    int c;

    while( (c = *str++) ) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash % SYMBOL_TABLE_SIZE;
}

void symtable_insert(char *name, hack_addr value) {
    Symbol *item = (Symbol*) malloc(sizeof(Symbol));
    item->address = value;
    item->name = (char *) malloc(strlen(name) + 1);
    strcpy(item->name, name);
    int hashIndex = hash(name);

    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->name != NULL) {
        ++hashIndex;

        hashIndex %= SYMBOL_TABLE_SIZE;
    }

    hashArray[hashIndex] = item;
}

Symbol *symtable_find(char *name) {
    int hashIndex = hash(name);

    while(hashArray[hashIndex] != NULL) {
        if(strcmp(hashArray[hashIndex]->name, name) == 0) {
            return hashArray[hashIndex];
        }
            ++hashIndex;

            hashIndex %= SYMBOL_TABLE_SIZE;
        
    }
    return NULL;
}

void symtable_display_table() {
    int i = 0;

    for(i = 0; i < SYMBOL_TABLE_SIZE; i++) {
        if(hashArray[i] != NULL) {
            printf(" (%s, %d) ", hashArray[i]->name, hashArray[i]->address);
        }
        else {
            printf(" ~~ ");
        }
    }
    printf("\n");
}