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

    /** Exercise 3 **/
        char prof[8] = {'P', 'a', 't', 'r', 'i', 'c', 'k', '\0'};

        if(strcmp(name, prof) < 0) {
            //strncmp < 0 => string 1 is less than string 2
            printf("%s is before %s.\n\n", name, prof);
        }
        else if(strcmp(name, prof) > 0) {
            //strncmp > 0 => string 1 is greater than string 2
            printf("%s is after %s.\n\n", name, prof);
        }
        else {
            //strncmp = 0 => string 1 is equal to string 2
            printf("%s is %s.\n\n", name, prof);
        }






    return 0;
}