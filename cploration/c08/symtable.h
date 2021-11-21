#ifndef __SYMTABLE_H__
#define __SYMTABLE_H__

#include<stdint.h>
#include<stdlib.h>
#include<stdio.h>

#define SYMBOL_TABLE_SIZE 100

typedef int16_t hack_addr;
typedef struct Symbol {
    char *name;
    hack_addr address;
} Symbol;

Symbol* hashArray[SYMBOL_TABLE_SIZE];

int hash(char *);
Symbol *find(char *);
void insert(char *, hack_addr);
void display_table();

#endif