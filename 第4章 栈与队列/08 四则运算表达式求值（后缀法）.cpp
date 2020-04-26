#include<iostream>
#include"expression.h"

using namespace std;

void main()
{
	Expression test;
	cout << "Enter a arithmetic expression: \n";
	string input;
	getline(cin, input);
	test.ResetData(input);
	test.Transfer();
	cout << "After transform: \n";
	cout << test.Trans_result() << endl;
	cout << "Calculate result is: \n";
	test.Calculate();
	cout << test.Result() << endl;
}
