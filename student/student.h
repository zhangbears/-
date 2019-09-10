
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//用户信息
typedef struct userInfo
{
	char userName[20];
	//char userAge;
	char userPassWord[20];
	struct userInfo *next;
	struct userInfo *pre;
}USERINFO;

//图书信息
typedef struct bookInfo
{
	char bookName[30];
	char bookAuthor[20];
	char bookNum[10];
	char bookPulisher[50];
	struct bookInfo *next;
	struct bookInfo *pre;
}BOOKINFO;

int createUserList();//注册用户信息

int adminCreateUser();//管理员管理用户信息

int createBookList();//创建图书信息

int printUserInfo();//输出用户信息

int printBookInfo();//输出图书信息

int userSave(USERINFO *head);//保存用户信息到文件

int bookSave(BOOKINFO *head);//保存图书信息到文件

int userDeleteSave(USERINFO *head);//需要重置用户内容的保存函数

int bookDeleteSave(BOOKINFO *head);//需要重置图书内容的保存函数

int menu1();//用户登录界面

int menu2();//注册和登陆选择界面

int menu3();//管理员界面

int menu4();//普通用户界面

int searchUser();//查找用户(管理员用)

int searchBook();//查找图书(通用)

int deleteUser();//删除用户

int deleteBook();//删除图书

USERINFO *userRead();//读取用户文件创建用户链表

BOOKINFO *bookRead();//读取图书文件创建图书链表


int prictise();//用来解决临时问题的
int openFile();

