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
	Init_board(mine, ROWS, COLS, '0');//��ʼ�����׵����� �š�0��
	Init_board(show, ROWS, COLS, '*');//��ʼ�����׵�����  �š�#��
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
		case 1:printf("��ʼ��Ϸ\n");
			game();
			break;
		case 0:printf("�˳���Ϸ\n");
			break;
		default:printf("���������������\n");
			break;
		}
	} while (choice);
	return 0;
}