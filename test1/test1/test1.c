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
	char board[N][M] = { 0 };//��Ҫһ��N*M�Ķ�ά����洢
	Init_board(board, N, M);//��ʼ��һ�����̣�����ո�
	show_board(board, N, M);//��ʾ����
	while (1)//������һ��ѭ������
	{
		play_move(board, N, M);//�������
		show_board(board, N, M);//����֮������ʾһ����ʾ����
		ret = who_win(board, N, M);//ret����һ������ֵ
		if (ret != 'C')
		{
			break;
		}
		compute_move(board, N, M);//���������
		show_board(board, N, M);//���������֮������ʾһ����ʾ����
		ret = who_win(board, N, M);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("�����Ӯ\n");
	}
	else if (ret == 'Q')
	{
		printf("ƽ��\n");
	}
}
main()
{
	srand((unsigned int)time(NULL));
	int choic;
	do {
		meau();
		printf("��ѡ�񡪡�>");
		scanf("%d", &choic);
		switch(choic)
		{
		case 1:
			game();
			break;
		case 0:printf("�˳�\n");
			break;
		default:printf("�����������ѡ��\n");
			break;
		}
	} while (choic);
	return 0;
}