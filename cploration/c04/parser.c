#include <parser.h>

void parse(FILE * file) {
    char line[MAX_LINE_LENGTH] = {0};
    // unsigned int line_num = 0;

    while(fgets(line, sizeof(line), file)) {
        strip(*line);
        if(!*line) { continue; }
        // line_num++;
        printf("%s", line);
    }
}

char *strip(char *s) {
    char s_new[sizeof s / sizeof s[0]] = {0};
    int i = 0;
    for(char *s2 = s; *s2; s2++) {
        if(s == '/' && *(s+1) == '/') { 
            break;
        } else if(!isspace(*s)) {
            s_new[i++] = *s2;
        }
    }
    s_new[i] = '\0';
    strcpy(s, s_new);
    
    return s;
}