#include<iostream>
#include<string>
#include"stringv1.h"

using namespace std;

void main()
{
	char test1[] = "This is a char array!";
	Stringv1 test2(test1);
	test2.Show();
	Stringv1 test3;
	test3 = test2;
	test3.Show();
	if (test3.ClearString())
		cout << "String is cleared!\n";
	if (!StrCompare(test1, test2))
		cout << "The two string is equal!\n";
	cout << "Substring: \n";
	cout << test2.SubString(5, 10) << endl;
	string s1 = "is";
	cout << "Find the first substring \"" << s1 << "\" at ";
	cout << test2.Index(s1, 1) << endl;

	string s2 = "at";
	cout << "Using \"" << s2 << "\" replace " << s1 << endl;
	int time = test2.Replace(s1, s2);
	cout << "After " << time << " time replace, the string is: ";
	test2.Show();

	string s3 = "insert ";
	cout << "After insert a string: \n";
	cout << test2.StrInsert(s3, 6) << endl;
}
