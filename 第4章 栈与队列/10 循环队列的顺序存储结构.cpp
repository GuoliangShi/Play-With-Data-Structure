#include<iostream>
#include<random>
#include<ctime>
#include<string>
#include"queuev2.h"

using namespace std;

void main()
{
	Queue<string> test;
	srand(time(0));
	while (!test.isFull()) {
		cout << "Enter the arrival customer name: \n";
		string name;
		getline(cin, name);
		test.EnQueue(name);
		cout << "There have " << test.Length() << " sustomers.\n\n";
	}
	while (!test.isEmpty()) {
		cout << test.DeQueue() << " leave, and " 
			<< test.Length() << " people remain.\n\n";
	}
}
