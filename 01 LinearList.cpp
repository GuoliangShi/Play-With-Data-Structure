#include<iostream>
#include"linearlist.h"
#include<random>
#include<ctime>

using namespace std;

void main()
{
	srand(time(0));
	LinearList<int> data1;
	LinearList<char> data2("This is a test about linearlist!");
	for (int i = 0; i < 11; i++) {
		if (data1.ListInsert(i, rand() % 10))
			cout << "Insert sucessed! \n";
		else
			cout << "Insert falied! \n";
		cout << "data1 = ";
		data1.show();
	}

	int lac;
	if (data2.LocateElem('s', lac)) {
		cout << "Find at " << lac << " !\n";
	}
	else
		cout << "No find!" << endl;

	LinearList<char> data3(data2);
	cout << "data3 = ";
	data3.show();

	LinearList<char> data4;
	data4 = data3;
	cout << "data4 = ";
	data4.show();

	LinearList<char> data5;
	data5 = data3 + data4;
	data5.show();

	while(!data2.ListEmpty()) {
		char temp;
		if (data2.ListDelete(rand() % data2.ListLength(), temp)) {
			cout << "Delete sucessed! \n";
			cout << "Delete " << temp << "  ";
		}else
			cout << "Delete falied! \n";
		cout << "data2 = ";
		data2.show();
	}

}
