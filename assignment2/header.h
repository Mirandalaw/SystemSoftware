#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<stdio.h>
#include<cstdlib>
#include<cstring>
#define MAX 1024
using namespace std;


typedef struct tagBook
{
	int id;
	string title;
	string author;
	string date;
	string publisher;
	int price;
}Book;

bool cmp(Book a,Book b);
bool cmpstr(Book a, Book b);
void write();
void dat(char *n,char *data);
void cut(char *str, char *cutof);
void read();
void write();
void start();
void info();
void menu1();
void menu3();
void menu3_1();
void menu4();
void menu5();
void menu6();
void menu0();