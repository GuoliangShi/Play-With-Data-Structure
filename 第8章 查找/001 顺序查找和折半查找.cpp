#include<iostream>
#include <iomanip>

using namespace std;

int Binary_Search(int *arr, const int n, const int key);
int Sequential_Search(int *arr, const int n, const int key);
int Sequential_Search2(int *arr, const int n, const int key);
int Binary_Search2(int *arr, int low, int hight, const int key);

void main()
{
	int arr[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17 };
	cout << "Find key = 0\n";
	cout << Sequential_Search(arr, 18, 0) << endl;
	cout << Sequential_Search2(arr, 18, 0) << endl;
	cout << Binary_Search(arr, 18, 0) << endl;
	cout << Binary_Search2(arr, 0, 18, 0) << endl;

	cout << "\nFind key = 15\n";
	cout << Sequential_Search(arr, 18, 15) << endl;
	cout << Sequential_Search2(arr, 18, 15) << endl;
	cout << Binary_Search(arr, 18, 15) << endl;
	cout << Binary_Search2(arr, 0, 18, 15) << endl;

	cout << "\nFind key = 20\n";
	cout << Sequential_Search(arr, 18, 20) << endl;
	cout << Sequential_Search2(arr, 18, 20) << endl;
	cout << Binary_Search(arr, 18, 20) << endl;
	cout << Binary_Search2(arr, 0, 18, 20) << endl;
}

int Sequential_Search(int *arr, const int n, const int key)
{
	for (int i = 0; i < n; i++) {
		if (arr[i] == key) {
			cout << "#Sequential_Search: Find key at ";
			return i;
		}
	}
	cout << "#Sequential_Search: Not find key, return ";
	return 0;
}

int Sequential_Search2(int *arr, const int n, const int key)
{
	if (arr[0] == key) {
		cout << "#Sequential_Search2: Find key at ";
		return 0;
	}
	int temp = arr[0];
	arr[0] = key;
	int i = n;
	while (arr[i] != key)
		i--;
	if (i != 0) {
		arr[0] = temp;
		cout << "#Sequential_Search2: Find key at ";
		return i;
	}
	else
	{
		arr[0] = temp;
		cout << "#Sequential_Search2: Not find key, return ";
		return 0;
	}
}

int Binary_Search(int *arr, const int n, const int key)
{
	int low = 0, hight = n - 1, mid;
	while (low <= hight)
	{
		// 折半查找
		//mid = (low + hight) / 2;
		// 插值查找
		mid = low + (double(key - arr[low]) / double(arr[hight] - arr[low]))*(hight - low);
		if (arr[mid] == key) {
			cout << "#Binary_Search: Find key at ";
			return mid;
		}
		else if (key < arr[mid])
			hight = mid - 1;
		else
			low = mid + 1;
	}
	cout << "#Binary_Search: Not find key, return ";
	return 0;
}

int Binary_Search2(int *arr, int low, int hight, const int key)
{
	int mid = (low + hight) / 2;
	if (arr[mid] == key) {
		cout << "#Binary_Search2: Find key at ";
		return mid;
	}
	else if (low > hight) {
		cout << "#Binary_Search2: Not find key, return ";
		return 0;
	}
	else if (key < arr[mid])
		Binary_Search2(arr, low, mid - 1, key);
	else
		Binary_Search2(arr, mid + 1, hight, key);
}
