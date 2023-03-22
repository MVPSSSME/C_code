#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100//����һ���洢100���˵�ͨѶ¼
#define MAX_NAME 10
#define MAX_SEX 10
#define MAX_NUMBER 12
#define MAX_HOME 10

typedef struct Preson{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char number[MAX_NUMBER];
	char home[MAX_HOME];
	int age;
}Person;//һ����Ŀ¼�����һ����Ϣ

typedef struct Contact {
	int index;//��¼����
	Person date[MAX];//������ϢĿ¼
}Contact;

void Initialize(Contact* pc);//��ʼ��

void ADD_address_book(Contact* pc);//��ͨѶ¼����

void DEL_address_book(Contact* pc);//��ͨѶ¼ɾ��

void FIND_address_book(Contact* pc);//����ͨѶ¼

void SORT_address_book(Contact* pc);//����ͨѶ¼

void SHOW_address_book(Contact* pc);//��ʾͨѶ¼

void MODIFY_address_book(Contact* pc);//�޸���Ϣ

