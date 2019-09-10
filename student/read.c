/*读取文件内容到链表*/

#include "student.h"

//读取用户文件到链表,得到用户链表的头指针
USERINFO *userRead()
{
	FILE *fp;
	USERINFO *readUserHead, *pnext, *plast;

	fp = fopen("userInfo.txt", "r");
	if (fp == NULL)
	{
		printf("open userInfo.txt failed!\n");
		exit(-1);
	}

	readUserHead = (USERINFO *)malloc(sizeof(USERINFO));
	plast = readUserHead;
	plast->next = NULL;
	plast->pre = NULL;

	pnext = (USERINFO *)malloc(sizeof(USERINFO));
	while (fread(pnext, sizeof(USERINFO), 1, fp))
	{
		plast->next = pnext;
		pnext->pre = plast;
		plast = plast->next;
		pnext = (USERINFO *)malloc(sizeof(USERINFO));
	}
	plast->next = NULL;
	free(pnext);
	fclose(fp);

	return readUserHead;
}

//读取图书文件到链表,得到图书链表的头指针
BOOKINFO *bookRead()
{
	FILE *fp;
	BOOKINFO *readBookHead, *pnext, *plast;

	fp = fopen("bookInfo.txt", "r");
	if (fp == NULL)
	{
		printf("open bookInfo.txt failed!\n");
		exit(-1);
	}

	readBookHead = (BOOKINFO *)malloc(sizeof(BOOKINFO));
	plast = readBookHead;
	plast->next = NULL;
	plast->pre = NULL;

	pnext = (BOOKINFO *)malloc(sizeof(BOOKINFO));
	while (fread(pnext, sizeof(BOOKINFO), 1, fp))
	{
		plast->next = pnext;
		pnext->pre = plast;
		plast = plast->next;
		pnext = (BOOKINFO *)malloc(sizeof(BOOKINFO));
	}
	plast->next = NULL;
	free(pnext);
	fclose(fp);

	return readBookHead;
}