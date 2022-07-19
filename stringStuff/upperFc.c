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
