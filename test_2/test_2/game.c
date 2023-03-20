#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

void Init_board(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board [i][j] = set;
		}
	}
}

void Show_board(char board[ROWS][COLS], int row, int col)
{
	int i, j;
	
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	putchar('\n');
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <=col; j++)
		{
			printf("%c ", board[i][j]);
		}
		putchar('\n');
	}

}

void Set_mine(char mine[ROWS][COLS], int row, int col)
{
	int x,y, count;
	count = COUNT;
	while (count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

void Fine_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x, y;
	int win = 0;
	
	while (win<row*col-COUNT)
	{
		printf("请输入坐标：");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] == '*')
			{
				if (mine[x][y] == '1')
				{
					printf("踩雷了，很遗憾。\n");
					break;
				}
				else
				{
					int count = Get_mine(mine, x, y);
					show[x][y] = count + '0';//标注出附件雷数
					Show_board(mine, ROW, COL);
					win++;
				}
			}
			else
			{
				printf("该位置已被排除\n");
			}
		}
		else
		{
			printf("输入错误，重新输入\n");
		}
	}
	if (win == row * col - COUNT)
	{
		printf("WIN!!!!!!!!!!!!\n");
		Show_board(mine, ROW, COL);
	}
}

int Get_mine(char mine[ROWS][COLS], int x, int y)
{
	return (mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0');
}