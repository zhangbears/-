#include "student.h"

//�����û���Ϣ���ļ�
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


//ɾ���û�ʱ���õı��溯��
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

//����ͼ����Ϣ���ļ�
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

//ɾ��ͼ����Ϣʱ���õ��ı��溯��
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