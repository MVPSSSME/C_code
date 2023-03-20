#pragma once//game.h写头文件
#include "game.h"
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#define N 3
#define M 3
void Init_board(char board[N][M], int n, int m);//函数的声名,初始化一个存放空格的二维棋盘
void show_board(char board[N][M], int n, int m);
void play_move(char board[N][M], int n, int m);
void compute_move(char board[N][M], int n, int m);
char who_win(char board[N][M], int n, int m);