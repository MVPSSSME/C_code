#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include"address_book.h"
void meun()
{
	printf("<----------------------------------->\n");
	printf("<-----1.add--------------2.del ----->\n");
	printf("<-----3.find-------------4.sort----->\n");
	printf("<-----5.show-------------6.modify--->\n");
	printf("<-----0.exit------------------------>\n");
	printf("<----------------------------------->\n");
}

enum Option {
	EXIT,
	add,
	del,
	find,
	sort,
	show,
	modify
};

int main()
{
	int choic;
	Contact con;
	Initialize(&con);
	do {
		meun();
		printf("请选择：");
		scanf("%d", &choic);
		switch (choic)
		{
		case add:
			ADD_address_book(&con);
			break;
		case del:
			DEL_address_book(&con);
			break;
		case find:
			FIND_address_book(&con);
			break;
		case sort:
			SORT_address_book(&con);
			break;
		case show:
			SHOW_address_book(&con);
			break;
		case modify:
			MODIFY_address_book(&con);
			break;
		case EXIT:
			DESTORY(&con);
			printf("退出\n");
			break;
		default:
			printf("输入错误，请重新选择\n");
			break;
		}
	} while (choic);
	return 0;
}