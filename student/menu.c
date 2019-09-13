#include "student.h"

//��¼����
int menu1()
{
	char name[20];
	char PassWord[20];
	FILE *fp;
	while (1)
	{
		printf("\t\t\t\tͼ��ϵͳ\t\t\t\t\n");
		printf("\t\t***************************************\n");
		printf("\t\t\t\t\t\t\t\t����exit�����ϼ�\n");
		printf("\t\t�û���:");
		scanf("%s", &name);
		if (strcmp(name, "exit") == 0)
		{
			return 0;
		}

		printf("\t\t����:");
		scanf("%s", &PassWord);

		fp = fopen("userInfo.txt", "r");
		if (fp == NULL)
		{
			printf("open user infomations file failed!\n");
			exit(-1);
		}

		USERINFO *head, *pnext, *plast;
		head = (USERINFO *)malloc(sizeof(USERINFO));
		plast = head;
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
		fclose(fp);

		pnext = head->next;
		while (pnext != NULL)
		{
			if (strcmp(name, pnext->userName) == 0 && strcmp(PassWord, pnext->userPassWord) == 0)
			{
				printf("name and password correct!\n");
				fclose(fp);
				if (strcmp(name, "admin") == 0)
				{
					system("CLS");
					menu3();		//ת������Ա����
					return 1;
				}
				else
				{
					system("CLS");
					menu4();		//ת����ͨ�û�����
					return 1;

				}
			}
			pnext = pnext->next;
		}
		printf("username is not exist or password is not correct!\n");

		system("PAUSE");
		system("CLS");
	}
	menu1();
	return 1;
}

//��ʱ�Ľ���
int menu2()
{
	int n;

	while (1)
	{
		printf("\t\t\t\tͼ��ϵͳ\t\t\t\t\n\n");
		printf("\t\t***************************************\n");
		printf("\t\t\t1.��¼\t2.ע��\t3.�˳�\n");
		scanf("%d", &n);
		if (n == 1)
		{
			system("CLS");
			menu1();
		}
		else if (n == 2)
		{
			system("CLS");
			createUserList();
			menu2();
		}
		else if (n == 3)
			exit(0);
		else		
			printf("choose the correct number!\n");
		
		system("PAUSE");
		system("CLS");
	}
	return 0;
}

//����Ա����
int menu3()
{
	int n;
	while (1)
	{
		printf("\t\t\t\t����Ա����\n\n");
		printf("\t\t***************************************\n");
		printf("\t1.�����˺�\t2.�����˺�\t3.�鿴�˺�\t4.ɾ���˺�\n\t5.����ͼ��\t6.����ͼ��\t7.�鿴ͼ��\t8.ɾ��ͼ��\n");
		printf("\t9.�˳�\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1:adminCreateUser();break;
		case 2:searchUser();break;
		case 3:printUserInfo();break;
		case 4:deleteUser();break;
		case 5:createBookList();break;
		case 6:searchBook();break;
		case 7:printBookInfo();break;
		case 8:deleteBook();break;
		case 9:return 0;break;
		default:break;
		}
		system("PAUSE");
		system("CLS");
	}
	return 0;
}

//��ͨ��Ա����
int menu4()
{
	int n;
	while (1)
	{
		printf("\t\t\t\t��Ա����\n\n");
		printf("\t\t***************************************\n");

		printf("\t1.�鿴ͼ��\t2.����  \t3.����  \n\t4.����ͼ��\t5.�˳�\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1:printBookInfo();break;
		case 2:printf("���ڽ���!\n");break;
		case 3:printf("���ڽ���!\n");break;
		case 4:searchBook();break;
		case 5:return 0;break;
		default:break;
		}

		system("PAUSE");
		system("CLS");
	}
	return 1;
}