#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

	printf("processed string: %s", str);
	return 0;
}
