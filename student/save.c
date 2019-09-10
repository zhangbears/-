#include "student.h"

//保存用户信息到文件
int userSave(USERINFO *head)
{
	FILE *fp;
	fp = fopen("userInfo.txt", "a");
	if (fp == NULL)
	{
		printf("open users file failed!\n");
		return -1;
	}

	USERINFO *pnext;
	pnext = head->next;

	while (pnext != NULL)
	{
		fwrite(pnext, sizeof(USERINFO), 1, fp);
		pnext = pnext->next;
	}

	fclose(fp);

	printf("save user infomations success!\n");

	return 1;
}


//删除用户时候用的保存函数
int userDeleteSave(USERINFO *head)
{
	FILE *fp;
	fp = fopen("userInfo.txt", "w");
	if (fp == NULL)
	{
		printf("open users file failed!\n");
		return -1;
	}

	USERINFO *pnext;
	pnext = head->next;

	while (pnext != NULL)
	{
		fwrite(pnext, sizeof(USERINFO), 1, fp);
		pnext = pnext->next;
	}

	fclose(fp);

	printf("save user infomations success!\n");

	return 1;
}

//保存图书信息到文件
int bookSave(BOOKINFO *head)
{
	FILE *fp;
	fp = fopen("bookInfo.txt", "a");
	if (fp == NULL)
	{
		printf("open file failed!\n");
		return (-1);
	}

	BOOKINFO *pnext;
	pnext = head->next;

	while (pnext != NULL)
	{
		fwrite(pnext, sizeof(BOOKINFO), 1, fp);
		pnext = pnext->next;
	}

	fclose(fp);

	printf("save book infomations success!\n");

	return 1;
}

//删除图书信息时候用到的保存函数
int bookDeleteSave(BOOKINFO *head)
{
	FILE *fp;
	fp = fopen("bookInfo.txt", "w");
	if (fp == NULL)
	{
		printf("open file failed!\n");
		return (-1);
	}

	BOOKINFO *pnext;
	pnext = head->next;

	while (pnext != NULL)
	{
		fwrite(pnext, sizeof(BOOKINFO), 1, fp);
		pnext = pnext->next;
	}

	fclose(fp);

	printf("save book infomations success!\n");

	return 1;
}