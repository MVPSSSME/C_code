#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void Init_board(char board[N][M], int n, int m)//初始化一个棋盘
{
	int i = 0, j = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <m; j++)
		{
			board[i][j] = ' ';
		}
	}
	//memset(board[0][0], ' ', n * m * sizof(board[0][0]));
}

void show_board(char board[N][M], int n, int m)//显示棋盘
{

	int i = 0, j = 0;
	/*for (i = 0; i < n; i++)
	{
		printf("%d ", i);
	}*/
	putchar('\n');
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < m - 1)
				printf("|");
		}
		putchar('\n');
		if (i < n - 1)
		{
			for (j = 0; j < m; j++)
			{
				printf("---");
				if (j < m - 1)
					printf("|");
			}
		}
		putchar('\n');
	}
}

void play_move(char board[N][M], int n, int m)//玩家输入两个数
{
	int x, y;
	printf("玩家下棋：\n");
	while (1)
	{
		printf("输入坐标：");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= N && y >= 1 && y <= M)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("已经被占用\n");
		}
		else
		{
			printf("输入错误\n");
		}
	}
}

void compute_move(char board[N][M], int n, int m)
{
	int x = 0, y = 0;
	printf("计算机下棋\n");
	while (1)
	{
		x = rand() % N;
		y = rand() % M;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

char who_win(char board[N][M], int n, int m)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]&&board[1][0]!=' ')
			return board[i][0];
	}

	for (i = 0; i < m; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i]&&board[0][i]!=' ')
			return board[i][0];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
		return board[1][1];
	if (IsFull(board, n, m))
	{
		return 'Q';
	}
	return 'C';
}

int IsFull(char board[N][M], int n, int m)
{
	int i = 0, j = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (board[i][j] == ' ')//判断棋盘有没有满
				return 0;
		}
	}
	return 1;
}