#include <stdio.h>
#include <string.h>

int rt_string(char* str, int size, FILE* stream) {
    if(fgets(str, size, stream) == NULL) {
        // saw EOF before any other chars or read error
        return 0;
    }
    size_t len = strlen(str);
    if(str[len-1] != '\n')
        rt_chompline(stream);
    else
        str[len-1] = '\0';
    return 1;
}

int rt_int(int* out, FILE* stream) {
}

int rt_chompline(FILE* stream) {
    int ch;
    while((ch = getchar()) != '\n')
        if(ch == EOF) return 0;
    return 1;
}
