#include<iostream>
#include"linearlist.h"
#include<random>
#include<ctime>

using namespace std;

void main()
{
	Node StaticLinkList[MAXSIZE];
	InitList(StaticLinkList);
	cout << "Enter initial value for List: \n";
	ListInsertHead(StaticLinkList);
	cout << "\nYour list is:\n";
	show(StaticLinkList);
	cout << "\nInsert a data:\n";
	ListInsert(StaticLinkList, 2);
	cout << "\nAfter insert a data:\n";
	show(StaticLinkList);
	ListDelete(StaticLinkList, 5);
	cout << "\nAfter delete a data:\n";
	show(StaticLinkList);
}
