#include<stdio.h>
#include<string.h>
#define MAX_LIMIT 100

int main() {
/** WARMUP **/
// declare a string with value
char hello[] = "Hello";
// declare an empty string
char name[MAX_LIMIT];

// prompt user
printf("What is your name? ");

// read in a string from user and save in variable
// [^\n] means to discard the newline character
scanf("%[^\n]s", name);

// print out "hello <name>"
printf("%s %s!\n\n", hello, name);

/** Exercise 1 **/ 
char welcome[MAX_LIMIT];
strcpy(welcome, hello);
strcat(welcome, " ");
strcat(welcome, name);
printf("%s!\n\n", welcome);

/** Exercise 2 **/
    int name_len = strlen(name);
    printf("Your name is %d characters long.\n\n", name_len);
    // strlen()
    return 0;
}