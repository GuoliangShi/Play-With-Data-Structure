#pragma once
#ifndef LINEARLIST_H_
#define LINEARLIST_H_

#include<string>

using namespace std;

class Book
{
private:
	string bookname;
	double price;
	double discount;
public:
	Book() {}
	Book(string bn, double pr, double di) :
		bookname(bn), price(pr), discount(di) {}
	string &BookName() { return bookname; }
	double Price() { return price; }
	double Discount() { return discount; }
};

struct Node
{
	Book data;
	struct Node *next;
};
typedef struct Node *LinkList;

bool GetElem(const LinkList &L, int i, Book &out)
{
	LinkList p = L->next;
	while (p) {
		if (i == 0) {
			out = p->data;
			return true;
		}
		p = p->next;
		i--;
	}
	return false;
}

void CreateListHead(LinkList &L, int n)
{
	L = new Node;
	L->next = NULL;
	for (int i = 0; i < n; i++) {
		LinkList p = new Node;
		cout << "Enter book name: ";
		string name;
		getline(cin, name);
		cout << "Enter book price: ";
		double pri;
		cin >> pri;
		cout << "Enter book discount: ";
		double dis;
		cin >> dis;
		while (cin.get() != '\n')
			continue;
		p->data = { name,pri,dis };
		p->next = L->next;
		L->next = p;
	}
}

void CreateListTail(LinkList &L, int n)
{
	L = new Node;
	L->next = NULL;
	LinkList r;
	r = L;
	for (int i = 0; i < n; i++) {
		LinkList p = new Node;
		cout << "Enter book name: ";
		string name;
		getline(cin, name);
		cout << "Enter book price: ";
		double pri;
		cin >> pri;
		cout << "Enter book discount: ";
		double dis;
		cin >> dis;
		while (cin.get() != '\n')
			continue;
		p->data = { name,pri,dis };
		r->next = p;
		r = p;
	}
	r->next = NULL;
}

void Show(LinkList & L)
{
	LinkList p = L->next;
	int i = 1;
	while (p) {
		cout << "Book " << i << " name: " << p->data.BookName() << endl;
		cout << "Book " << i << " price: " << p->data.Price() << endl;
		cout << "Book " << i << " discount: " << p->data.Discount() << endl;
		i++;
		p = p->next;
	}
}

bool ListInsert(LinkList & L, int i, Book e)
{
	LinkList p = L;
	while (p) {
		if (i == 0) {
			LinkList s = new Node;
			s->data = e;
			s->next = p->next;
			p->next = s;
			return true;
		}
		p = p->next;
		i--;
	}
	return false;
}

bool ListDelete(LinkList &L, int i, Book &e)
{
	LinkList p = L;
	while (p) {
		if (i == 0) {
			LinkList q = p->next;
			p->next = q->next;
			e = q->data;
			free(q);
			return true;
		}
		p = p->next;
		i--;
	}
	return false;
}

void ClearList(LinkList &L)
{
	LinkList p = L, q;
	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	L->next = NULL;
}
 
#endif // !LINEARLIST
