#include<iostream>
#define UNLLKEY -32768

using namespace std;

struct HashTable
{
	int *elem;
	int count;
};

int HASHSIZE;

bool InitHashTable(HashTable &H)
{
	cout << "Please input Hash Table size: ";
	cin >> H.count;
	HASHSIZE = H.count;
	H.elem = new int[H.count];
	for (int i = 0; i < H.count; i++)
		H.elem[i] = UNLLKEY;
	return true;
}

int Hash(const int key)
{
	return key%HASHSIZE;
}

bool InsertHash(HashTable &H, const int key)
{
	int add = Hash(key);
	while (H.elem[add] != UNLLKEY)
		add = (add + 1) % HASHSIZE;
	H.elem[add] = key;
	return true;
}

bool SearchHash(HashTable &H, const int key, int &add)
{
	add = Hash(key);
	while (H.elem[add] != key) {
		add = (add + 1) % HASHSIZE;
		if (H.elem[add] == UNLLKEY || add == Hash(key))
			return false;
	}
	return true;
}

void main()
{
	HashTable H;
	InitHashTable(H);
	int temp, i = 0;
	cout << "#" << i + 1 << " (q to quite): ";
	while(i<HASHSIZE&&cin >> temp) {
		InsertHash(H, temp);
		i++;
		if (i == HASHSIZE)
			break;
		cout << "#" << i + 1 << " (q to quite): ";
	}
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cout << "Enter number you want to find: ";
	cin >> temp;
	int add;
	if (SearchHash(H, temp, add))
		cout << "Find " << H.elem[add] << " at " << add << ".\n";
	else
		cout << "There is no " << temp << endl;
}
