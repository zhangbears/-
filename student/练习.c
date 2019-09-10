#include "student.h"

typedef struct stu
{
	int age;
	char name[20];
	struct stu *next;
	//struct stu *pre;
}student;

//int main(void)
//{
//	//student stu1;
//	student *head;
//	student *pnext;
//	student *plast;
//	char c;
//	head = (student *)malloc(sizeof(student));
//	head->next = NULL;
//	head->pre = NULL;
//	plast = head;
//	while ((c = getchar()) != '\n')
//	{
//		pnext = (student *)malloc(sizeof(student));
//		pnext->age = c;
//		plast->next = pnext;
//		pnext->pre = plast;
//		plast = plast->next;//指针后移
//	}
//	plast->next = NULL;
//
//	pnext = head->next;
//	
//	while (pnext != NULL)
//	{
//		printf("%c", pnext->age);
//		pnext = pnext->next;
//	}
//
//}
int prictise(void)
{
	FILE *fp;
	student *head, *next, *temp;
	int n = 0;

	fp = fopen("temp.txt", "a");
	if (fp == NULL)
	{
		printf("打开失败!\n");
		exit(-1);
	}
	else
		printf("success!\n");

	head = (student *)malloc(sizeof(student));
	next = head;
	next->next = NULL;
	while (1)
	{
		temp = (student *)malloc(sizeof(student));

		printf("input name:");
		scanf("%s", temp->name);
		printf("input age:");
		scanf("%d", &temp->age);
		fprintf(fp, temp);
		next->next = temp;
		next = temp;
		printf("continue?\n1.yes\t2.no\n");
		scanf("%d", &n);
		if (n == 2)
			break;
	}
	next->next = NULL;
	fclose(fp);

	return 1;
}

int openFile()
{
	FILE *fp;
	student *head, *pnext, *plast;

	fp = fopen("temp.txt", "r");
	if (fp == NULL)
	{
		printf("open temp.txt failed!\n");
		exit(-1);
	}

	head = (student *)malloc(sizeof(student));
	plast = head;
	plast->next = NULL;

	while (1)
	{
		pnext = (student *)malloc(sizeof(student));
		fscanf(fp, pnext);
		printf("age = %d\tname = %s", pnext->age, pnext->name);
		plast->next = pnext;
		plast = pnext;
		getchar();
	}
	plast->next = NULL;

	return 1;
}