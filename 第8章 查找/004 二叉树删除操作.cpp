#include<iostream>

using namespace std;

typedef int TypeName;

struct Node
{
	TypeName data;
	Node *lchild, *rchild;
};

typedef Node* Tree;

void Creat_Tree(Tree &T);
bool SearchTree(Tree T, int key, Tree f, Tree &p);
bool InsertTree(Tree &T, int key);
bool ShowTree(const Tree &T);
bool DeleteBST(Tree &T, int key);
bool Delete_Node(Tree &T);

void main()
{
		Tree T = nullptr;
		cout << "Enter number(62 58 47 35 0 37 0 0 51 0 0 0 88 73 0 0 99 93 0 0 0): \n";
		Creat_Tree(T);
	
		Tree p;
		if (SearchTree(T, 73, nullptr, p))
			cout << p << ": " << p->data << endl;
		else
			cout << "There is no key!\n" << endl;

		Tree T1 = nullptr;
		int num[] = { 62, 58, 47, 35, 37, 51, 88, 73, 99, 93 };
		for (int temp : num)
			InsertTree(T1, temp);
		if (InsertTree(T1, 95)) {
			ShowTree(T1);
			cout << endl;
		}
		else
			cout << "Insert fail!" << endl;

		if (DeleteBST(T1, 62)) {
			ShowTree(T1);
			cout << endl;
		}
		else
			cout << "Delete fail!" << endl;

}

void Creat_Tree(Tree &T)
{
	TypeName temp;
	cin >> temp;
	if (temp == 0) {
		T = nullptr;
	}
	else {
		T = new Node;
		T->data = temp;
		Creat_Tree(T->lchild);
		Creat_Tree(T->rchild);
	}
}

bool SearchTree(Tree T, int key, Tree f, Tree &p)
{
	if (!T) {
		p = f;
		return false;
	}
	else {
		if (T->data == key) {
			p = T;
			return true;
		}
		else if (T->data > key)
			SearchTree(T->lchild, key, T, p);
		else
			SearchTree(T->rchild, key, T, p);
	}
}

bool InsertTree(Tree &T, int key)
{
	Tree p, s;
	if (!SearchTree(T, key, nullptr, p)) {
		s = new Node;
		s->data = key;
		s->lchild = nullptr;
		s->rchild = nullptr;
		if (!p)
			T = s;
		else if (p->data > key)
			p->lchild = s;
		else
			p->rchild = s;
		return true;
	}
	else
		return false;
}

bool ShowTree(const Tree &T)
{
	if (T == nullptr)
		return false;
	else
	{
		cout << T->data << " ";
		ShowTree(T->lchild);
		ShowTree(T->rchild);
	}
	return true;
}

bool DeleteBST(Tree &T, int key)
{
	if (!T)
		return false;
	else {
		if (T->data == key)
			Delete_Node(T);
		else if (T->data > key)
			DeleteBST(T->lchild, key);
		else
			DeleteBST(T->rchild, key);
	}
}

bool Delete_Node(Tree &p)
{
	Tree q, s;
	if (p->lchild == nullptr) {
		p = p->rchild;
		delete p;
	}
	else if (p->rchild == nullptr) {
		p = p->lchild;
		delete p;
	}
	else {
		q = p; s = p->lchild;
		while (s->rchild) {
			q = s; s = s->rchild;
		}
		p->data = s->data;
		if (q != p)
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;
		delete s;
	}
	return true;
}
