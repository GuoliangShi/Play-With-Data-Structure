#pragma once
#ifndef STACK_H_
#define STACK_H_

#define MAXSIZE 1000

template<typename T>
class sqStack 
{
private:
	T data[MAXSIZE];
	int top;
public:
	sqStack();
	T GetTop() const;
	bool Push(const T &e);
	bool Pop();
	bool isEmpty() const;
	bool isFull() const;
	void ClearStack();
};

template<typename T>
sqStack<T>::sqStack() 
{
	top = -1;
}

template<typename T>
T sqStack<T>::GetTop() const
{
	if (isEmpty()) {
		cout << "The stack is empty!\n";
		exit(EXIT_FAILURE);
	}
	else
		return data[top];
}

template<typename T>
bool sqStack<T>::Push(const T &e)
{
	if (isFull())
		return false;
	else {
		top += 1;
		data[top] = e;
	}
}

template<typename T>
bool sqStack<T>::Pop()
{
	if (isEmpty())
		return false;
	else {
		top -= 1;
	}
	return true;
}

template<typename T>
bool sqStack<T>::isEmpty() const
{
	return (top == -1);
}

template<typename T>
bool sqStack<T>::isFull() const
{
	return (top == MAXSIZE - 1);
}

template<typename T>
void sqStack<T>::ClearStack()
{
	top = -1;
}

#endif
