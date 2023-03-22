#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100//定义一个存储100个人的通讯录
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
}Person;//一个人目录里面的一下信息

typedef struct Contact {
	int index;//记录个数
	Person date[MAX];//个人信息目录
}Contact;

void Initialize(Contact* pc);//初始化

void ADD_address_book(Contact* pc);//给通讯录增加

void DEL_address_book(Contact* pc);//给通讯录删除

void FIND_address_book(Contact* pc);//查找通讯录

void SORT_address_book(Contact* pc);//排序通讯录

void SHOW_address_book(Contact* pc);//显示通讯录

void MODIFY_address_book(Contact* pc);//修改信息

