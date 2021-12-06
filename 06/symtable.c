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
    // item->name = name;
    int hashIndex = hash(name);
    // printf("Before added\nitem address: %d, item name: %s, length: %lu\n", item->address, item->name, strlen(item->name));

    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->name != NULL) {
        ++hashIndex;

        hashIndex %= SYMBOL_TABLE_SIZE;
    }

    hashArray[hashIndex] = item;
    // printf("Before free\nCollection address: %d, collection name: %s\n", hashArray[hashIndex]->address, hashArray[hashIndex]->name);

    // free(item);
    // printf("After added\nCollection address: %d, collection name: %s\n", hashArray[hashIndex]->address, hashArray[hashIndex]->name);
}

Symbol *symtable_find(char *name) {
    // printf("Name Argument: %s, length: %lu\n", name, strlen(name));
    int hashIndex = hash(name);

    while(hashArray[hashIndex] != NULL) {
        // printf("Argument: %s, symtable: %s\n", name, hashArray[hashIndex]->name);
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
            printf(" (%s, %d) ",hashArray[i]->name, hashArray[i]->address);        }
        else {
            printf(" ~~ ");
        }
    }
    printf("\n");
}