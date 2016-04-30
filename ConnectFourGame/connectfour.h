/* Xuhang Liu --- Connect Four Game Bonus Assignment
Student ID: 11134687
CPTS 121   due MAY 6th*/



#ifndef  CONNECT_FOUR_H
#define  CONNECT_FOUR_H
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

#define ROWS 6
#define COLS 7

void print_board(char *board);
int place_token(char *board, int player, const char*);
int check_win(char *board);
int isfour(char *board, int, int, int, int);
int ishorizontal(char *board);
int isvertical(char *board);
int isdiagonal(char *board);


#endif // ! CONNECT_FOUR_H