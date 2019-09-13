#include "student.h"

//��ӡ�û���Ϣ����Ļ
int printUserInfo()
{
	USERINFO *userHead, *pnext;

	userHead = userRead();
	pnext = userHead->next;
	printf("user_name\t\tuser_password\n");
	printf("************************************\n");

	while (pnext != NULL)
	{
		printf("%12s\t%20s\n", pnext->userName, pnext->userPassWord);
		pnext = pnext->next;
	}
	printf("printUserInfo��������!\n");
	return 0;
}

//��ӡͼ����Ϣ����Ļ
int printBookInfo()
{
	BOOKINFO *bookHead,*pbook;
	
	bookHead = bookRead();
	pbook = bookHead->next;

	printf("\t\t\tbook_name\t\tbookAuthor\t\t\t\tbookPublisher\t\tbooknumber\n");
	printf("*****************************************************************************\n\n");
	while (pbook != NULL)
	{
		printf("%28s\t%20s\t%50s\t%10s\n", pbook->bookName, pbook->bookAuthor, pbook->bookPulisher, pbook->bookNum);
		pbook = pbook->next;
	}
	printf("printBookInfo��������!\n");
	return 1;
}