#pragma once
#ifndef QUEUEV2_H_
#define QUEUEV2_H_

template<typename T>
struct Node
{
	T data;
	Node * next;
};

template<typename T>
class Queue
{
private:
	Node<T> *front;
	Node<T> *rear;
	int length;
public:
	Queue();
	bool InQueue(T &e);
	T OutQueue();
	bool isEmpty() const;
	int Length() const;
};

template<typename T>
Queue<T>::Queue()
{
	Node<T> * p = new Node<T>;
	front = rear = p;
	length = 0;
}

template<typename T>
bool Queue<T>::InQueue(T &e)
{
	Node<T> *p = new Node<T>;
	p->data = e;
	p->next = nullptr;
	rear->next = p;
	rear = p;
	length++;
	return true;
}

template<typename T>
T Queue<T>::OutQueue()
{
	Node<T> *p = front->next;
	if (p->next == nullptr) {
		rear = front;
		T out = p->data;
		delete p;
		length--;
		return out;
	}
	else if (isEmpty())
	{
		cout << "The queue is empty!!!" << endl;
		exit(EXIT_FAILURE);
	}
	else
	{
		front->next = p->next;
		T out = p->data;
		delete p;
		length--;
		return out;
	}
}

template<typename T>
bool Queue<T>::isEmpty() const
{
	return(front == rear);
}

template<typename T>
int Queue<T>::Length() const
{
	return length;
}

#endif // !QUEUEV2_H_
