
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//�û���Ϣ
typedef struct userInfo
{
	char userName[20];
	//char userAge;
	char userPassWord[20];
	struct userInfo *next;
	struct userInfo *pre;
}USERINFO;

//ͼ����Ϣ
typedef struct bookInfo
{
	char bookName[30];
	char bookAuthor[20];
	char bookNum[10];
	char bookPulisher[50];
	struct bookInfo *next;
	struct bookInfo *pre;
}BOOKINFO;

int createUserList();//ע���û���Ϣ

int adminCreateUser();//����Ա�����û���Ϣ

int createBookList();//����ͼ����Ϣ

int printUserInfo();//����û���Ϣ

int printBookInfo();//���ͼ����Ϣ

int userSave(USERINFO *head);//�����û���Ϣ���ļ�

int bookSave(BOOKINFO *head);//����ͼ����Ϣ���ļ�

int userDeleteSave(USERINFO *head);//��Ҫ�����û����ݵı��溯��

int bookDeleteSave(BOOKINFO *head);//��Ҫ����ͼ�����ݵı��溯��

int menu1();//�û���¼����

int menu2();//ע��͵�½ѡ�����

int menu3();//����Ա����

int menu4();//��ͨ�û�����

int searchUser();//�����û�(����Ա��)

int searchBook();//����ͼ��(ͨ��)

int deleteUser();//ɾ���û�

int deleteBook();//ɾ��ͼ��

USERINFO *userRead();//��ȡ�û��ļ������û�����

BOOKINFO *bookRead();//��ȡͼ���ļ�����ͼ������


int prictise();//���������ʱ�����
int openFile();

