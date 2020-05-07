#include<iostream>

using namespace std;

struct Node
{
	int data;
	Node *lchird, *rchild;
};

typedef Node* Tree;
void Creat_tree(Tree &T);
bool SearchBST(const Tree T, int key, Tree f, Tree &p);

void main()
{
	Tree T = nullptr;
	cout << "Enter number(62 58 47 35 0 37 0 0 51 0 0 0 88 73 0 0 99 93 0 0 0): ";
	Creat_tree(T);

	Tree p;
	if (SearchBST(T, 73, nullptr, p))
		cout << p << ": " << p->data << endl;
	else
		cout << "There is no key!" << endl;
}

void Creat_tree(Tree &T)
{
	int temp;
	cin >> temp;
	if (temp == 0)
		T = nullptr;
	else
	{
		T = new Node;
		T->data = temp;
		Creat_tree(T->lchird);
		Creat_tree(T->rchild);
	}
}

bool SearchBST(const Tree T, int key, Tree f, Tree &p)
{
	if (!T) {
		p = f;
		return false;
	}
	else if (T->data == key) {
		p = T;
		return true;
	}
	else if (T->data > key) {
		SearchBST(T->lchird, key, T, p);
	}
	else {
		SearchBST(T->rchild, key, T, p);
	}
}
