#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define COUNT 79

void Init_board(char board[ROWS][COLS], int rows, int cols,char set);
void Show_board(char board[ROWS][COLS], int row, int col);
void Set_mine(char mine[ROW][COL], int row, int col);
void Fine_mine(char mine[ROWS][COLS], char shoe[ROWS][COLS], int row, int col);