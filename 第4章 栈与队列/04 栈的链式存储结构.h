#pragma once
#ifndef STACK_H_
#define STACK_H_

template<typename T>
struct Node
{
	T data;
	Node *next;
};

template<typename T>
class chStack
{
private:
	Node<T> * top;
	int count;
public:
	chStack();
	bool Push(T &e);
	bool Pop(T &e);
	bool isEmpty();
	T &GetTop();
	int Length() const;
};

template<typename T>
chStack<T>::chStack()
{
	top = nullptr;
	count = 0;
}

template<typename T>
bool chStack<T>::Push(T &e)
{
	Node<T> *p = new Node<T>;
	p->data = e;
	p->next = top;
	top = p;
	count++;
	return true;
}

template<typename T>
bool chStack<T>::Pop(T &e)
{
	if (isEmpty())
		return false;
	else
	{
		Node<T> * temp = top;
		e = top->data;
		top = top->next;
		count--;
		delete temp;
	}
	return true;
}

template<typename T>
T &chStack<T>::GetTop()
{
	if (isEmpty()) {
		cout << "The stack is empty!\n";
		exit(EXIT_FAILURE);
	}
	else
		return top->data;
}

template<typename T>
bool chStack<T>::isEmpty()
{
	return(count == 0);
}

template<typename T>
int chStack<T>::Length() const
{
	return count;
}

#endif
