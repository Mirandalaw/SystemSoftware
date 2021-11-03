#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#define MAX 100

typedef struct AccountBook {
int number;
char deposit[10];
char item[20];
char date[20];
int usedAmount;
int currentAmount;
}Book;
typedef struct left{
int withdraw;
int deposit;
int count;
}s;
void intro();
void showAllData(Book* account, s *statusMoney,int cnt);
void showDeposit(Book* account, int cnt);
void showWithdraw(Book* account, int cnt);
void addDepositInformation(Book* a,s *b);
void addWithdrawInformation(Book* a,s *b);
void showToFindItem(Book* account, int cnt);
void fixItem(Book* account, int cnt);
void eraseData(Book* account,s* leftMoney, int cnt);
void endProgram();
void goProgram();
