#include "student.h"

//普通用户注册
int createUserList()
{
	USERINFO *useHead, *pnext, *plast;
	char tempPassWord[20];
	int n;
	useHead = (USERINFO *)malloc(sizeof(USERINFO));
	useHead->pre = NULL;
	useHead->next = NULL;
	plast = useHead;

	printf("\t\t\t\t用户注册界面\n\n");
	printf("\t\t*******************************************\n");
	while (1)
	{
		pnext = (USERINFO *)malloc(sizeof(USERINFO));
		printf("input username:");
		scanf("%s", pnext->userName);
		printf("set your password:");
		scanf("%s", pnext->userPassWord);
		printf("input your password again:");
		scanf("%s", tempPassWord);
		if (strcmp(pnext->userPassWord, tempPassWord))
		{
			printf("input error!");
			system("CLS");
			continue;
		}
		plast->next = pnext;
		pnext->pre = plast;
		plast = plast->next;
		printf("create success!\n");
		break;
	}
	plast->next = NULL;

	printf("是否保存?\n");
	printf("\t\t1.是\t2.否\n");
	scanf("%d", &n);
	if (n == 1)
	{
		userSave(useHead);		
	}
	system("PAUSE");
	system("CLS");
	return 1;
}

//管理员创建用户信息
int adminCreateUser()
{
	USERINFO *useHead, *pnext, *plast;
	int n;
	useHead = (USERINFO *)malloc(sizeof(USERINFO));
	useHead->pre = NULL;
	useHead->next = NULL;
	plast = useHead;

	printf("\t\t\t\t管理用户界面\n\n");
	printf("\t\t*******************************************\n");

	while (1)
	{
		pnext = (USERINFO *)malloc(sizeof(USERINFO));
		printf("input username:");
		scanf("%s", pnext->userName);
		printf("set your password:");
		scanf("%s", pnext->userPassWord);

		plast->next = pnext;
		pnext->pre = plast;
		plast = plast->next;

		printf("create success!\tcontinue ?\n");
		printf("\t\t\t1.Yes\t2.No\n");
		scanf("%d", &n);
		if (n == 1)
			continue;
		else if (n == 2)
			break;
		else
		{
			printf("input error!\n");
			continue;
		}
	}
	plast->next = NULL;

	printf("是否保存?\n");
	printf("\t\t\t1.是\t2.否\n");
	scanf("%d", &n);
	if (n == 1)
	{
		userSave(useHead);		
	}

	return 1;
}

//管理员创建图书信息
int createBookList()
{
	BOOKINFO *bookHead, *pnext, *plast;
	int n;
	bookHead = (BOOKINFO *)malloc(sizeof(BOOKINFO));
	plast = bookHead;
	plast->next = NULL;
	plast->pre = NULL;
	while (1)
	{
		pnext = (BOOKINFO *)malloc(sizeof(BOOKINFO));
		printf("input bookName:");
		scanf("%s", pnext->bookName);
		printf("input bookAuthor:");
		scanf("%s", pnext->bookAuthor);
		printf("input bookPulisher:");
		scanf("%s", pnext->bookPulisher);
		printf("input bookNumber:");
		scanf("%s", pnext->bookNum);

		plast->next = pnext;
		pnext->pre = plast;
		plast = plast->next;

		printf("continue ?\n");
		printf("\t\t1.Yes\t2.No\n");
		scanf("%d", &n);
		if (n == 1)
			continue;
		else if (n == 2)
		{
			break;
		}
		else
		{
			printf("choose error!\n");
			//system("CLS");
			continue;
		}
	}
	plast->next = NULL;

	printf("是否保存?\n");
	printf("\t\t1.是\t2.否\n");
	scanf("%d", &n);
	if (n == 1)
	{
		bookSave(bookHead);		
	}

	return 1;
}