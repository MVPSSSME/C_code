#pragma once//game.hдͷ�ļ�
#include "game.h"
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#define N 3
#define M 3
void Init_board(char board[N][M], int n, int m);//����������,��ʼ��һ����ſո�Ķ�ά����
void show_board(char board[N][M], int n, int m);
void play_move(char board[N][M], int n, int m);
void compute_move(char board[N][M], int n, int m);
char who_win(char board[N][M], int n, int m);