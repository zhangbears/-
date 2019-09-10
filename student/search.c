#include "student.h"

int searchUser()
{
	USERINFO *head, *pnext;
	int flag = 0;
	char name[20];

	head = userRead();

	//查找符合条件的用户
	printf("请输入要查找的用户:");
	scanf("%s", &name);
	pnext = head->next;

	while (pnext != NULL)
	{
		if (strcmp(name, pnext->userName) == 0)
		{
			printf("%20s\t%20s\n", pnext->userName, pnext->userPassWord);
			flag++;
		}
		pnext = pnext->next;
	}

	if (flag == 0)
	{
		printf("没有找到用户!\n");
	}
	else
		printf("一共有%d个%s的用户", flag, name);	
	return 0;
}

int searchBook()
{

	BOOKINFO *head, *pnext;
	int flag = 0;
	char bookname[20];

	head = bookRead();
	printf("input book name:");
	scanf("%s", bookname);
	pnext = head->next;

	printf("\t\t\tbook_name\t\tbookAuthor\t\t\t\tbookPublisher\t\tbooknumber\n");
	printf("*****************************************************************************\n\n");
	while (pnext != NULL)
	{
		if (strcmp(bookname, pnext->bookName) == 0)
		{
			printf("%28s\t%20s\t%50s\t%10s\n", pnext->bookName, pnext->bookAuthor, pnext->bookPulisher, pnext->bookNum);
			flag++;
		}
		pnext = pnext->next;
	}
	if (flag == 0)
		printf("没有找到图书!\n");
	else
		printf("一共找到%d本图书\n", flag);

	return 0;
}