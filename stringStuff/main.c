/*
      ____        ___  __                 _  __
     /  _/______ / _ \/ /  ___  ___  ___ | |/_/
    _/ // __/ -_) ___/ _ \/ _ \/ _ \/ -_)>  <
   /___/\__/\__/_/  /_//_/\___/_//_/\__/_/|_|
   Author: Kenneth Soares
   Website: ken-soares.github.io
   File: stringStuff/main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main(void){

	char *str;
	printf("enter a word> ");
	scanf("%s",str);

	char ch;
	printf("enter a character to delete >");
	scanf(" %c", &ch);

	int size = strlen(str);
	for(int i = 0; i < size; i++){
		if(str[i] == ch){
			for(int j = i; j< size; j++){
				str[j] = str[j+1];
			}
			i--;
		}
	}

	printf("processed string: %s\n", str);
	printf("processed string uppercase: %s", upperc(str));
	return 0;
}
