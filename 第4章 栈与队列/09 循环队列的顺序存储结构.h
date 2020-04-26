#pragma once
#ifndef QUEUEV2_H_
#define QUEUEV2_H_

#define MAXSIZE 5

template<typename T>
class Queue
{
private:
	T data[MAXSIZE];
	int front;
	int rear;
public:
	Queue();
	bool isEmpty() const;
	bool isFull() const;
	bool EnQueue(T &e);
	T DeQueue();
	int Length() const;
};

template<typename T>
Queue<T>::Queue()
{
	front = 0;
	rear = 0;
}

template<typename T>
bool Queue<T>::isEmpty() const
{
	return(front == rear);
}

template<typename T>
bool Queue<T>::isFull() const
{
	return((rear + 1) % MAXSIZE == front);
}

template<typename T>
bool Queue<T>::EnQueue(T &e)
{
	if (isFull()) {
		cout << "The queue is full!!!\n";
		return false;
	}
	else {
		data[rear] = e;
		rear = (rear + 1) % MAXSIZE;
		return true;
	}
}

template<typename T>
T Queue<T>::DeQueue()
{
	if (isEmpty()) {
		cout << "The queue is empty!!!\n";
		exit(EXIT_FAILURE);
	}
	else {
		T e = data[front];
		front = (front + 1) % MAXSIZE;
		return e;
	}
}

template<typename T>
int Queue<T>::Length() const
{
	return(rear - front + MAXSIZE) % MAXSIZE;
}

#endif // !QUEUEV2_H_
