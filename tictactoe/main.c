/*
      ____        ___  __                 _  __
     /  _/______ / _ \/ /  ___  ___  ___ | |/_/
    _/ // __/ -_) ___/ _ \/ _ \/ _ \/ -_)>  <
   /___/\__/\__/_/  /_//_/\___/_//_/\__/_/|_|
   Author: Kenneth Soares
   Website: ken-soares.github.io
   File: tictactoe/main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "main.h"


char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBoard(){
	for(int i = 0;i<3;i++){
		for(int j = 0;j<3;j++){
			board[i][j] = ' ';
		}
	}
}

void printBoard(){
	printf(" %c | %c | %c",board[0][0], board[0][1],board[0][2]);
	printf("\n---|---|---\n");
	printf(" %c | %c | %c",board[1][0], board[1][1],board[1][2]);
	printf("\n---|---|---\n");
	printf(" %c | %c | %c",board[2][0], board[2][1],board[2][2]);
	printf("\n");
}

int checkFreeSpaces(){
	int freeSpaces = 9;
	for(int i = 0;i<3;i++){
		for(int j = 0;j<3;j++){
			if(board[i][j] != ' '){
				freeSpaces--;
			}
		}
	}

	return freeSpaces;
}


void playerMove(){
	int x;
	int y;

	do{
		printf("enter a column number (1-3) >");
		scanf("%d",&y);
		printf("enter a row number (1-3) >");
		scanf("%d",&x);
		y--;
		x--;
		if(board[x][y] != ' '){
			printf("Invalid move\n");
		}else{
			board[x][y] = PLAYER;
			break;
		}
	}while(board[x][y] != ' ');

}

char checkWinner(){
	for(int i = 0; i<3; i++){
		if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
			return board[i][0];
		}
	}
	for(int i = 0; i<3; i++){
		if(board[0][i] == board[1][i] && board[0][i] == board[2][i]){
			return board[0][i];
		}
	}

	if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){
		return board[0][0];
	}

	if(board[0][2] == board[1][1] && board[0][2] == board[2][0]){
		return board[0][2];
	}

	return ' ';
}

void computerMove(){
	srand(time(0));
	int x;
	int y;

	if(checkFreeSpaces() > 0){
		do{
			x = rand() % 3;
			y = rand() % 3;
		}while(board[x][y] != ' ');

		board[x][y] = COMPUTER;
	}else{
		printWinner(' ');
	}
}

void printWinner(char winner){
	if(winner == PLAYER){
		printf("player has won the game!");
	}else if(winner == COMPUTER){
		printf("The computer has won the game!");
	}else{
		printf("it's a tie.");
	}
}
int main(){
	char winner = ' ';
	resetBoard();
	while(winner == ' ' && checkFreeSpaces() != 0){
		printBoard();
		playerMove();
		winner = checkWinner();
		if(winner != ' ' || checkFreeSpaces() == 0){
			break;
		}
		computerMove();
		winner = checkWinner();
		if(winner != ' ' || checkFreeSpaces() == 0){
			break;
		}
	}

	printBoard();
	printWinner(winner);
	return 0;
}
