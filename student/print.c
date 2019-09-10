#include "student.h"

//打印用户信息到屏幕
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
	printf("printUserInfo函数结束!\n");
	return 0;
}

//打印图书信息到屏幕
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
	printf("printBookInfo函数结束!\n");
	return 1;
}