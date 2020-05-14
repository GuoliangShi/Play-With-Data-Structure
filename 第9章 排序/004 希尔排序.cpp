#include<iostream>

using namespace std;

#define MAXSIZE 100

struct List
{
	int data[MAXSIZE];
	int size;
};

void swap(List &L, int i, int j)
{
	int temp = L.data[i];
	L.data[i] = L.data[j];
	L.data[j] = temp;
}

void show(const List &L)
{
	for (int i = 0; i < L.size; i++)
		cout << L.data[i] << " ";
	cout << endl;
}

void ShellSort(List &L)
{
	for (int increment = L.size / 2; increment > 0; increment /= 2) {
		for (int i = increment; i < L.size; i++) {
			if (L.data[i] < L.data[i - increment]) {
				int temp = L.data[i],j;
				for (j = i - increment; j >= 0 && temp < L.data[j]; j -= increment)
					L.data[j + increment] = L.data[j];
				L.data[j + increment] = temp;
			}
		}
	}
}

void main()
{
	List test;
	cout << "Input number (q to quite): ";
	int temp;
	test.size = 0;
	while (test.size <= MAXSIZE&&cin >> temp) {
		test.data[test.size] = temp;
		test.size += 1;
		//cout << "Input number (q to quite): ";
	}
	cin.clear();
	cin.ignore(100, '\n');
	cout << "Your input List is: ";
	show(test);
	cout << "After sort: ";
	ShellSort(test);
	show(test);
}
