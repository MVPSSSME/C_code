#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void meau()
{
	printf("<------------------------>\n");
	printf("<---------1.play--------->\n");
	printf("<---------0.exit--------->\n");
	printf("<------------------------>\n");
}
void game()
{
	char ret = 0;
	char board[N][M] = { 0 };//需要一个N*M的二维数组存储
	Init_board(board, N, M);//初始化一个棋盘，放入空格
	show_board(board, N, M);//显示棋盘
	while (1)//下棋是一个循环过程
	{
		play_move(board, N, M);//玩家下棋
		show_board(board, N, M);//下棋之后在显示一次显示棋盘
		ret = who_win(board, N, M);//ret接收一个返回值
		if (ret != 'C')
		{
			break;
		}
		compute_move(board, N, M);//计算机下棋
		show_board(board, N, M);//计算机下棋之后在显示一次显示棋盘
		ret = who_win(board, N, M);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("计算机赢\n");
	}
	else if (ret == 'Q')
	{
		printf("平局\n");
	}
}
main()
{
	srand((unsigned int)time(NULL));
	int choic;
	do {
		meau();
		printf("请选择——>");
		scanf("%d", &choic);
		switch(choic)
		{
		case 1:
			game();
			break;
		case 0:printf("退出\n");
			break;
		default:printf("输入错误，重新选择\n");
			break;
		}
	} while (choic);
	return 0;
}