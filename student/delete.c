#include "student.h"

int deleteUser()
{	
	USERINFO *puser,*head;
	char *username[20];

	printf("������Ҫɾ���û�������:");
	scanf("%s", &username);

	head = userRead();
	puser = head->next;
	while (puser != NULL)
	{
		if (strcmp(username, puser->userName) == 0)
		{
			//�ж��Ƿ��������β�ڵ�
			if (puser->next == NULL)
			{				
				puser->pre->next = NULL;
				puser->pre = NULL;
				free(puser);
				break;
			}
			puser->next->pre = puser->pre;
			puser->pre->next = puser->next;	
			printf("��ɾ��%s��Ϣ!\n", username);
		}
		puser = puser->next;
	}
	userDeleteSave(head);//ɾ����Ϻ�洢���ļ�
	return 0;
}

int deleteBook()
{
	BOOKINFO *pbook, *head;
	char *bookname[30];

	printf("������Ҫɾ��ͼ�������:");
	scanf("%s", bookname);

	head = bookRead();
	pbook = head->next;

	while (pbook != NULL)
	{
		//�ҵ�Ҫɾ������,��ɾ��
		if (strcmp(bookname, pbook->bookName) == 0)
		{
			//�ж��Ƿ�����������һ���ڵ�
			if (pbook->next == NULL)
			{
				pbook->pre->next = NULL;
				pbook->pre = NULL;
				free(pbook);
				break;
			}
			pbook->next->pre = pbook->pre;
			pbook->pre->next = pbook->next;
			printf("��ɾ��%s��Ϣ!\n", bookname);
		}
		pbook = pbook->next;
	}
	bookDeleteSave(head);//ɾ����Ϻ�洢���ļ�
	return 0;
}