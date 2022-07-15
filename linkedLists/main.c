/*
      ____        ___  __                 _  __
     /  _/______ / _ \/ /  ___  ___  ___ | |/_/
    _/ // __/ -_) ___/ _ \/ _ \/ _ \/ -_)>  <
   /___/\__/\__/_/  /_//_/\___/_//_/\__/_/|_|

   Author: Kenneth Soares
   Website: ken-soares.github.io
   File: linkedLists/main.c
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	struct node *next;
} node_t;

void printlist(node_t *head){
	node_t *temporary = head;
	while(temporary != NULL){
		printf("%d - ",temporary->value);
		temporary = temporary->next;
	}
	printf("\n");
}

node_t *create_new_node(int value){
	node_t *result = malloc(sizeof(node_t));
	result->value = value;
	result->next = NULL;
	return result;
}


// **head = on demande l'adresse du pointeur sur struct du nom de head
node_t *insert_at_head(node_t **head, node_t *node_to_insert){
	node_to_insert->next = *head;
	*head = node_to_insert;
	return node_to_insert;
}

void insert_after_node(node_t *node_to_insert_after, node_t *new_node){
	new_node->next = node_to_insert_after->next;
	node_to_insert_after->next = new_node;
}

node_t *find_node(node_t *head, int value){
	node_t *tmp = head;
	while(tmp != NULL){
		if(tmp->value == value) return tmp;
		tmp = tmp->next;
	}

	return NULL;
}

int main(){
	node_t *head = NULL;
	node_t *tmp;

	for(int i = 0; i<25;i++){
		tmp = create_new_node(i);
		insert_at_head(&head,tmp);
	}

	tmp = find_node(head,13);
	printf("found node with value %d\n", tmp->value);

	insert_after_node(tmp,create_new_node(75));
	printlist(head);
	return 0;
}
