#define _CRT_SECURE_NO_WARNINGS
#include"address_book.h"


void Initialize(Contact* pc)
{
	pc->index = 0;
	memset(pc->date, 0, sizeof(pc->date));
}//把结构体全部初始化位0
static int FIND_NAME(const Contact*pc,char name[])
{
	int i = 0;
	for (i = 0; i < pc->index; i++)
	{
		if (0 == strcmp(pc->date[i].name, name))
		{
			return i;
		}
	}
	return -1;
}

void ADD_address_book(Contact* pc)
{
	if (pc->index == MAX)//index是结构体里的数据，所以要用结构体指针表示
	{
		printf("以存满\n");
		return;
	}
	printf("请输入名字：\n");
	scanf("%s", pc->date[pc->index].name);
	printf("请输入性别：\n");
	scanf("%s", pc->date[pc->index].sex);
	printf("请输入号码：\n");
	scanf("%s", pc->date[pc->index].number);
	printf("请输入地址：\n");
	scanf("%s", pc->date[pc->index].home);
	printf("请输入年龄：\n");
	scanf("%d",&(pc->date[pc->index].age));
	pc->index++;
	printf("添加成功\n");
}

void SHOW_address_book(Contact* pc)
{
	int i = 0;
	for (i = 0; i < pc->index; i++)
	{
		printf("名字：%s 性别：%s 电话：%s 家庭：%s 年龄：%d\n", 
			pc->date[i].name,
			pc->date[i].sex,
			pc->date[i].number,
			pc->date[i].home,
			pc->date[i].age);
	}
}

void DEL_address_book(Contact* pc)
{
	char name[MAX_NAME];
	if (pc->index == 0)
	{
		printf("通讯录无信息\n");
		return;
	}
	printf("请输入删除的名字：\n");
	scanf("%s", name);
	int flag = FIND_NAME(pc,name);
	if (flag == -1)
	{
		printf("没有此人。\n");
		return;
	}
	int i = 0;
	for (i = flag; i < pc->index; i++)
	{
		pc->date[i] = pc->date[i + 1];
	}
	pc->index--;
	printf("完成\n");
}

void FIND_address_book(Contact* pc)
{
	char name[MAX_NAME];
	printf("请输入要找到名字\n");
	scanf("%s", name);
	int flag = FIND_NAME(pc, name);
	if (flag == -1)
	{
		printf("通讯录无信息\n");
		return;
	}
	int i = flag;
	printf("名字：%s 性别：%s 电话：%s 家庭：%s 年龄：%d\n",
		pc->date[i].name,
		pc->date[i].sex,
		pc->date[i].number,
		pc->date[i].home,
		pc->date[i].age);
}

void MODIFY_address_book(Contact* pc)
{
	char name[MAX_NAME];
	printf("请输入要改的名字\n");
	scanf("%s", name);
	int flag = FIND_NAME(pc, name);
	if (flag == -1)
	{
		printf("通讯录无信息\n");
		return;
	}
	int i = flag;
	printf("请输入名字：\n");
	scanf("%s", pc->date[i].name);
	printf("请输入性别：\n");
	scanf("%s", pc->date[i].sex);
	printf("请输入号码：\n");
	scanf("%s", pc->date[i].number);
	printf("请输入地址：\n");
	scanf("%s", pc->date[i].home);
	printf("请输入年龄：\n");
	scanf("%d", &(pc->date[i].age));
	pc->index++;
	printf("改正成功\n");
}

int cmp(const void* p1, const void* p2)
{
	return strcmp(((Person*)p1)->name, ((Person*)p2)->name);
}
//根据名字排序
void SORT_address_book(Contact* pc)
{
	qsort(pc->date, pc->index, sizeof(Person),cmp);
	printf("排序完成\n");
}