#include "main.h"

int putchr(char c){
    write(1,&c,1);
    return 0;
}

void putstr(char *str){
    while(str != NULL && *str != '\0'){
        putchr(*str);        
        str++;
    }
}

void putalphabet(){

    char letter = 'a';

    while(letter <= 'z'){
        putchr(letter);
        letter++;
    }
}
