#pragma once
#ifndef STACK_H_
#define STACK_H_

#define MAXSIZE 1000

template<typename T>
class sqStack 
{
private:
	T data[MAXSIZE];
	int top1;
	int top2;
public:
	sqStack();
	T GetTop(int c) const;
	bool Push(const T &e, int c);
	bool Pop(int c);
	bool isEmpty(int c) const;
	bool isFull() const;
	void ClearStack(int c);
};

template<typename T>
sqStack<T>::sqStack() 
{
	top1 = -1;
	top2 = MAXSIZE;
}

template<typename T>
T sqStack<T>::GetTop(int c) const
{
	if (isEmpty(c)) {
		cout << "The stack is empty!\n";
		exit(EXIT_FAILURE);
	}
	else {
		if (c == 1)
			return data[top1];
		else if (c == 2)
			return data[top2];
	}
}

template<typename T>
bool sqStack<T>::Push(const T &e, int c)
{
	if (isFull())
		return false;
	else {
		if (c == 1) {
			top1 += 1;
			data[top1] = e;
		}
		else if (c == 2) {
			top2 -= 1;
			data[top2] = e;
		}
	}
}

template<typename T>
bool sqStack<T>::Pop(int c)
{
	if (isEmpty(c))
		return false;
	else {
		if (c == 1)
			top1 -= 1;
		else if (c == 2)
			top2 += 1;
	}
	return true;
}

template<typename T>
bool sqStack<T>::isEmpty(int c) const
{
	if(c==1)
		return (top1 == -1);
	if (c == 2)
		return (top2 == MAXSIZE);
}

template<typename T>
bool sqStack<T>::isFull() const
{
	return (top1 + 1 == top2);
}

template<typename T>
void sqStack<T>::ClearStack(int c)
{
	if (c == 1)
		top1 = -1;
	else if (c == 2)
		top2 = MAXSIZE;
} 

#endif
