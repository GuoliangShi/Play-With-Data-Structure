#include<iostream>
#include"linearlist.h"
#include<random>
#include<ctime>

using namespace std;

void main()
{
	LinkList test1;
	CreateListHead(test1, 2);
	cout << "\nYour data is: " << endl;
	Show(test1);

	if (ListInsert(test1, 1, { "BOOK THIEF",66.3,0.8 })) {
		cout << "\nAfter insert a data: " << endl;
		Show(test1);
	}

	Book out;
	if (GetElem(test1, 1, out)) {
		cout << "\nGet data : " << endl;
		cout << "Book name: " << out.BookName() << endl;
		cout << "Book price: " << out.Price() << endl;
		cout << "Book discount: " << out.Discount() << endl;
	}

	if (ListDelete(test1, 1, out)) {
		cout << "\nAfter delete a data: " << endl;
		Show(test1);
	}

	ClearList(test1);
	cout << "\nAfter clear list: " << endl;
	Show(test1);
}  
