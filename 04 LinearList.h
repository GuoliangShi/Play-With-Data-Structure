#pragma once
#ifndef LINEARLIST_H_
#define LINEARLIST_H_

#include<string>
using namespace std;

const int MAXSIZE = 10000;

struct Node
{
	string data;
	int cur;
};

bool InitList(Node *sl)
{
	for (int i = 0; i < MAXSIZE-1; i++)
		sl[i].cur = i + 1;
	sl[MAXSIZE - 1].cur = 1;
	return true;
}

int Malloc_SLL(Node *sl)
{
	int i = sl[0].cur;
	if(i)
		sl[0].cur = sl[i].cur;
	return i;
}

int ListLength(Node *sl)
{
	int index = sl[MAXSIZE - 1].cur;
	int k = 0;
	while (index) {
		index = sl[index].cur;
		k++;
	}
	return k;
}

bool ListInsertHead(Node *sl)
{
	string input;
	int insert;
	cout << "Enter a new string data (q to quit): ";
	getline(cin, input);
	while(input != "q"){
		insert = Malloc_SLL(sl);
		sl[insert].data = input;
		cout << "Enter a new string data (q to quit): ";
		getline(cin, input);
	}
	sl[insert].cur = 0;
	return true;
}

bool ListInsert(Node *sl, int i)
{
	if (i<1 || i>ListLength(sl) + 1)
		return false;

	int insert = Malloc_SLL(sl);
	string input;
	cout << "Enter a new string data: ";
	getline(cin, input);
	sl[insert].data = input;

	int index = sl[MAXSIZE - 1].cur;
	for (int k = 1; k < i-1; k++)
		index = sl[index].cur;

	sl[insert].cur = sl[index].cur;
	sl[index].cur = insert;
	return true;
}

void show(Node *sl)
{
	int idx = sl[MAXSIZE - 1].cur;
	int i = 1;
	while (idx) {
		cout << "# " << i << ": " << sl[idx].data << endl;
		i++;
		idx = sl[idx].cur;
	}
}

void free_SLL(Node * ls, int i)
{
	ls[i].cur = ls[0].cur;
	ls[0].cur = i;
}

bool ListDelete(Node *sl, int k)
{
	if (k<1 || k>ListLength(sl))
		return false;
	int index = sl[MAXSIZE - 1].cur;
	for (int i = 1; i < k - 1; i++)
		index = sl[index].cur;

	int temp = sl[index].cur;
	sl[index].cur = sl[temp].cur;
	free_SLL(sl, temp);
}
 
#endif // !LINEARLIST
