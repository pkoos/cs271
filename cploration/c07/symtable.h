#include<stdint.h>

#define SYMBOL_TABLE_SIZE 100

typedef int16_t hack_addr;
typedef struct Symbol {
    hack_addr addr;
    char *name;
} Symbol;

Symbol* hashArray[SYMBOL_TABLE_SIZE];

int hash(char *);
Symbol *find(char *);
void insert(char *, hack_addr);
void display_table();