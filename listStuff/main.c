/*
      ____        ___  __                 _  __
     /  _/______ / _ \/ /  ___  ___  ___ | |/_/
    _/ // __/ -_) ___/ _ \/ _ \/ _ \/ -_)>  <
   /___/\__/\__/_/  /_//_/\___/_//_/\__/_/|_|
   Author: Kenneth Soares
   Website: ken-soares.github.io
   File: listStuff/main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "main.h"

void findMax(int *list){

	int max = list[0];
	for(int i = 0; i < sizeof(list)/sizeof(int)+1;i++){
		if(list[i] > max){
			max = list[i];
		}
	}
	printf("The maximum value is %d\n", max);
}

void findMin(int *list){
	int min = list[0];
	for(int i = 0; i < sizeof(list)/sizeof(int)+1;i++){
		if(list[i] < min){
			min = list[i];
		}
	}
	printf("The minimal value is %d\n", min);
}
int *askInput(int *list){
	char end;
	int i = 0;
	while(tolower(end) != 'n'){
		list = realloc(list,(i+1)*sizeof(int));
		printf("enter an int> ");
		scanf("%d", &list[i]);
		printf("enter another int?> ");
		scanf(" %c", &end);
		i++;
	}

	return list;
}

int findSum(int *list){
	int sum = 0;
	for(int i = 0; i < sizeof(list)/sizeof(int)+1;i++){
		sum += list[i];
	}
	return sum;
}

int *bubble_sort(int *list){
	int length = sizeof(list)/sizeof(list[0]);
	for(int i = 0; i < length; i++){
		for(int j = 0; j < length;j++){
			if(list[j] > list[j+1]){
				int tmp = list[j];
				list[j] = list[j+1];
				list[j+1] = tmp;
			}
		}
	}

	return list;
}

int main(void){

	int *list = malloc(sizeof(int));
	list = askInput(list);
	findMax(list);
	findMin(list);
	int sum = findSum(list);
	printf("The sum of all the items in the list is %d\n", sum);

	list = bubble_sort(list);
	for(int i = 0; i < sizeof(list)/sizeof(list[0]) + 1;i++){
		printf("list element %d\n", list[i]);
	}
	return 0;
}
