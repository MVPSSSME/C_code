#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void meau()
{
	printf("<------------------------>\n");
	printf("<---------1.play--------->\n");
	printf("<---------0.exit--------->\n");
	printf("<------------------------>\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	Init_board(mine, ROWS, COLS, '0');//初始化放雷的棋盘 放“0”
	Init_board(show, ROWS, COLS, '*');//初始化排雷的棋盘  放“#”
	Show_board(show, ROW, COL);
	Set_mine(mine, ROW, COL);
	Show_board(mine, ROW, COL);
	Fine_mine(mine, show, ROW, COL);
}
int main()
{
	srand((unsigned int)time(NULL));
	int choice;
	do {
		meau();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:printf("开始游戏\n");
			game();
			break;
		case 0:printf("退出游戏\n");
			break;
		default:printf("输入错误，重新输入\n");
			break;
		}
	} while (choice);
	return 0;
}