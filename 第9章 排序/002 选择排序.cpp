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

void SelectSort(List &L)
{
	for (int i = 0; i < L.size - 1; i++) {
		int idx = i;
		for (int j = i+1; j < L.size; j++) {
			idx = L.data[idx] < L.data[j] ? idx : j;
		}
		swap(L, i, idx);
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
	cout << "After bubble sort: ";
	SelectSort(test);
	show(test);
}
