#include<iostream>
#include<string>
#include"stack.h"

using namespace std;

void main()
{
	sqStack<string> book;
	book.Push("BOOK THIEF");
	book.Push("KITE RUNNER");
	book.Push("THE OLD MAN");
	cout << book.GetTop() << endl;
	book.Pop();
	cout << book.GetTop() << endl;
	book.ClearStack();
	cout << book.GetTop() << endl;
}
