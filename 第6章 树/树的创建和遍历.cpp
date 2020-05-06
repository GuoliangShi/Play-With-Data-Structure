#include<iostream>
#include<string>

using namespace std;
typedef char ElemType;

struct Node
{
	ElemType data;
	Node * lchild;
	Node * rchild;
};

typedef Node* Tree;

void CreateTreePre(Tree &T);
void PreOrderTraverse(Tree T, int level);
void InOrderTraverse(Tree T, int level);
void PostOrderTraverse(Tree T, int level);
void operate(ElemType ch, int level);

void main()
{
	Tree test1 = nullptr;
	cout << "Enter characters in the preorder traversal: \n";
	CreateTreePre(test1);
	int level = 1;
	cout << "With PreOrderTraverse: \n";
	PreOrderTraverse(test1, level);
	cout << "With InOrderTraverse: \n";
	InOrderTraverse(test1, level);
	cout << "With PostOrderTraverse: \n";
	PostOrderTraverse(test1, level);
}

void CreateTreePre(Tree &T)
{
	ElemType ch;
	cin >> ch;
	if (ch == '#')
		T = nullptr;
	else
	{
		T = new Node;
		T->data = ch;
		CreateTreePre(T->lchild);
		CreateTreePre(T->rchild);
	}
}

void operate(ElemType ch, int level)
{
	cout << ch << " at " << level << " level.\n";
}

void PreOrderTraverse(Tree T, int level)
{
	if (T == nullptr)
		return;
	operate(T->data, level);
	PreOrderTraverse(T->lchild, level + 1);
	PreOrderTraverse(T->rchild, level + 1);
}

void InOrderTraverse(Tree T, int level)
{
	if (T == nullptr)
		return;
	InOrderTraverse(T->lchild, level + 1);
	operate(T->data, level);
	InOrderTraverse(T->rchild, level + 1);
}

void PostOrderTraverse(Tree T, int level)
{
	if (T == nullptr)
		return;
	PostOrderTraverse(T->lchild, level + 1);
	PostOrderTraverse(T->rchild, level + 1);
	operate(T->data, level);
}
