#define _CRT_SECURE_NO_WARNINGS
#include"address_book.h"


void Initialize(Contact* pc)
{
	pc->index = 0;
	memset(pc->date, 0, sizeof(pc->date));
}//�ѽṹ��ȫ����ʼ��λ0
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
	if (pc->index == MAX)//index�ǽṹ��������ݣ�����Ҫ�ýṹ��ָ���ʾ
	{
		printf("�Դ���\n");
		return;
	}
	printf("���������֣�\n");
	scanf("%s", pc->date[pc->index].name);
	printf("�������Ա�\n");
	scanf("%s", pc->date[pc->index].sex);
	printf("��������룺\n");
	scanf("%s", pc->date[pc->index].number);
	printf("�������ַ��\n");
	scanf("%s", pc->date[pc->index].home);
	printf("���������䣺\n");
	scanf("%d",&(pc->date[pc->index].age));
	pc->index++;
	printf("��ӳɹ�\n");
}

void SHOW_address_book(Contact* pc)
{
	int i = 0;
	for (i = 0; i < pc->index; i++)
	{
		printf("���֣�%s �Ա�%s �绰��%s ��ͥ��%s ���䣺%d\n", 
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
		printf("ͨѶ¼����Ϣ\n");
		return;
	}
	printf("������ɾ�������֣�\n");
	scanf("%s", name);
	int flag = FIND_NAME(pc,name);
	if (flag == -1)
	{
		printf("û�д��ˡ�\n");
		return;
	}
	int i = 0;
	for (i = flag; i < pc->index; i++)
	{
		pc->date[i] = pc->date[i + 1];
	}
	pc->index--;
	printf("���\n");
}

void FIND_address_book(Contact* pc)
{
	char name[MAX_NAME];
	printf("������Ҫ�ҵ�����\n");
	scanf("%s", name);
	int flag = FIND_NAME(pc, name);
	if (flag == -1)
	{
		printf("ͨѶ¼����Ϣ\n");
		return;
	}
	int i = flag;
	printf("���֣�%s �Ա�%s �绰��%s ��ͥ��%s ���䣺%d\n",
		pc->date[i].name,
		pc->date[i].sex,
		pc->date[i].number,
		pc->date[i].home,
		pc->date[i].age);
}

void MODIFY_address_book(Contact* pc)
{
	char name[MAX_NAME];
	printf("������Ҫ�ĵ�����\n");
	scanf("%s", name);
	int flag = FIND_NAME(pc, name);
	if (flag == -1)
	{
		printf("ͨѶ¼����Ϣ\n");
		return;
	}
	int i = flag;
	printf("���������֣�\n");
	scanf("%s", pc->date[i].name);
	printf("�������Ա�\n");
	scanf("%s", pc->date[i].sex);
	printf("��������룺\n");
	scanf("%s", pc->date[i].number);
	printf("�������ַ��\n");
	scanf("%s", pc->date[i].home);
	printf("���������䣺\n");
	scanf("%d", &(pc->date[i].age));
	pc->index++;
	printf("�����ɹ�\n");
}

int cmp(const void* p1, const void* p2)
{
	return strcmp(((Person*)p1)->name, ((Person*)p2)->name);
}
//������������
void SORT_address_book(Contact* pc)
{
	qsort(pc->date, pc->index, sizeof(Person),cmp);
	printf("�������\n");
}