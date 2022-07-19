/*
      ____        ___  __                 _  __
     /  _/______ / _ \/ /  ___  ___  ___ | |/_/
    _/ // __/ -_) ___/ _ \/ _ \/ _ \/ -_)>  <
   /___/\__/\__/_/  /_//_/\___/_//_/\__/_/|_|
   Author: Kenneth Soares
   Website: ken-soares.github.io
   File: stringStuff/upperFC.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *upperc(char* word){
	char* result = (char*)malloc(strlen(word) * sizeof(char));
	for(int i = 0; i < strlen(word);i++){
		result[i] = word[i] - 32;
	}
	return result;
}
