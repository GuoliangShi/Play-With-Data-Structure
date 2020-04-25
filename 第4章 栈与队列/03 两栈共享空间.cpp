#include<iostream>
#include<string>
#include"stack.h"

using namespace std;

void main()
{
	sqStack<string> book;
	book.Push("BOOK THIEF",1);
	book.Push("KITE RUNNER",2);
	book.Push("THE OLD MAN",1);
	cout << book.GetTop(1) << endl;
	cout << book.GetTop(2) << endl;
	book.Pop(1);
	cout << book.GetTop(1) << endl;
	book.ClearStack(1);
	cout << book.GetTop(1) << endl;
}
