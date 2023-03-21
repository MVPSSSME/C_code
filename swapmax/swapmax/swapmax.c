#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
char* swap(char* st)
{
	int len = strlen(st);
	int i = 0;
	if (len == 1)
	{
		return st;
	}
	while (i < len - 1)
	{
		if (st[i] < st[i + 1])
		{
			char tmp = st[i];
			st[i] = st[i + 1];
			st[i + 1] = tmp;
			break;
		}
		i++;
	}
	return st;
}
int main()
{
	char arr[100] = { 0 };
	scanf("%s", arr);
	char* ans = swap(arr);
	printf("%s\n", ans);
	return 0;
}