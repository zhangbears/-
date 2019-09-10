#include "student.h"

int deleteUser()
{	
	USERINFO *puser,*head;
	char *username[20];

	printf("请输入要删除用户的名字:");
	scanf("%s", &username);

	head = userRead();
	puser = head->next;
	while (puser != NULL)
	{
		if (strcmp(username, puser->userName) == 0)
		{
			//判断是否是链表的尾节点
			if (puser->next == NULL)
			{				
				puser->pre->next = NULL;
				puser->pre = NULL;
				free(puser);
				break;
			}
			puser->next->pre = puser->pre;
			puser->pre->next = puser->next;	
			printf("已删除%s信息!\n", username);
		}
		puser = puser->next;
	}
	userDeleteSave(head);//删除完毕后存储到文件
	return 0;
}

int deleteBook()
{
	BOOKINFO *pbook, *head;
	char *bookname[30];

	printf("请输入要删除图书的名字:");
	scanf("%s", bookname);

	head = bookRead();
	pbook = head->next;

	while (pbook != NULL)
	{
		//找到要删除的书,并删除
		if (strcmp(bookname, pbook->bookName) == 0)
		{
			//判断是否是链表的最后一个节点
			if (pbook->next == NULL)
			{
				pbook->pre->next = NULL;
				pbook->pre = NULL;
				free(pbook);
				break;
			}
			pbook->next->pre = pbook->pre;
			pbook->pre->next = pbook->next;
			printf("已删除%s信息!\n", bookname);
		}
		pbook = pbook->next;
	}
	bookDeleteSave(head);//删除完毕后存储到文件
	return 0;
}