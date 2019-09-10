#include "student.h"

//登录界面
int menu1()
{
	char name[20];
	char PassWord[20];
	FILE *fp;
	while (1)
	{
		printf("\t\t\t\t图书系统\t\t\t\t\n");
		printf("\t\t***************************************\n");
		printf("\t\t\t\t\t\t\t\t输入exit返回上级\n");
		printf("\t\t用户名:");
		scanf("%s", &name);
		if (strcmp(name, "exit") == 0)
		{
			return 0;
		}

		printf("\t\t密码:");
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
					menu3();		//转到管理员界面
					return 1;
				}
				else
				{
					system("CLS");
					menu4();		//转到普通用户界面
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

//打开时的界面
int menu2()
{
	int n;

	while (1)
	{
		printf("\t\t\t\t图书系统\t\t\t\t\n\n");
		printf("\t\t***************************************\n");
		printf("\t\t\t1.登录\t2.注册\t3.退出\n");
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

//管理员界面
int menu3()
{
	int n;
	while (1)
	{
		printf("\t\t\t\t管理员界面\n\n");
		printf("\t\t***************************************\n");
		printf("\t1.新增账号\t2.查找账号\t3.查看账号\t4.删除账号\n\t5.增加图书\t6.查找图书\t7.查看图书\t8.删除图书\n");
		printf("\t9.退出\n");
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

//普通成员界面
int menu4()
{
	int n;
	while (1)
	{
		printf("\t\t\t\t会员界面\n\n");
		printf("\t\t***************************************\n");

		printf("\t1.查看图书\t2.借书  \t3.还书  \n\t4.查找图书\t5.退出\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1:printBookInfo();break;
		case 2:printf("正在建立!\n");break;
		case 3:printf("正在建立!\n");break;
		case 4:searchBook();break;
		case 5:return 0;break;
		default:break;
		}

		system("PAUSE");
		system("CLS");
	}
	return 1;
}