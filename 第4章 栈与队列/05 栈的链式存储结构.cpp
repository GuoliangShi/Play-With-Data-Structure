#include<iostream>
#include<string>
#include"stack.h"

using namespace std;

void main()
{
	chStack<string> test;
	int tim = 1;
	cout << tim <<"# Enter your favorite book name (q to quit): \n";
	string book;
	while (getline(cin, book)) {
		if (book == "q")
			break;
		else
			test.Push(book);
		tim++;
		cout << tim << "# Enter your favorite book name (q to quit): \n";
	}

	cout << "\nThe number of the stack element is: ";
	cout << test.Length() << endl;
	cout << "The top of the stack is: ";
	cout << test.GetTop() << endl;

	int num = test.Length();
	string out;
	for (int i = 0; i < num; i++) {
		if (test.Pop(out)) {
			cout << "\nPop element " << out << endl;
			cout << "The number of the stack element is: ";
			cout << test.Length() << endl;
		}
	}
}
