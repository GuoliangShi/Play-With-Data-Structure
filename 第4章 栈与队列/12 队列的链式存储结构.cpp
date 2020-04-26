#include<iostream>
#include<string>
#include"queuev2.h"

using namespace std;

void main()
{
	Queue<string> test;
	for (int i = 0; i < 3;i++) {
		cout << "Enter the arrival customer name: \n";
		string name;
		getline(cin, name);
		test.InQueue(name);
		cout << "There have " << test.Length() << " customers.\n\n";
	}
	while (!test.isEmpty()) {
		cout << test.OutQueue() << " leave, and ";
		cout << test.Length() << " people remain.\n";
	}
}
