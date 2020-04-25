#pragma once
#ifndef LINEARLIST_H_
#define LINEARLIST_H_

#include<string>
using namespace std;
#define MaxSize 100

template<typename T>
class LinearList
{
private:
	T data[MaxSize];
	int length;
public:
	LinearList();
	LinearList(T *s);
	LinearList(const LinearList & lt);
	bool ListEmpty() const;
	bool ListFull() const;
	T GetElem(int i);
	bool LocateElem( T e, int &l) const;
	bool ListInsert(int i, T e);
	bool ListDelete(int i, T &e);
	const int ListLength();
	void show() const;
	LinearList &operator=(const LinearList & lt);
	LinearList &operator+(const LinearList & lt1);
};

template<typename T>
LinearList<T>::LinearList()
{
	length = 0;
}

template<typename T>
LinearList<T>::LinearList(T *s)
{
	int size = strlen(s);
	for (int i = 0; i < size; i++)
		data[i] = s[i];
	length = size;
}

template<typename T>
LinearList<T>::LinearList(const LinearList & lt)
{
	for (int i = 0; i < lt.length; i++)
		data[i] = lt.data[i];
	length = lt.length;
}

template<typename T>
bool LinearList<T>::ListEmpty() const
{
	return length == 0;
}

template<typename T>
bool LinearList<T>::ListFull() const
{
	return length == MaxSize;
}

template<typename T>
T LinearList<T>::GetElem(int i)
{
	return data[i];
}

template<typename T>
bool LinearList<T>::LocateElem(T e, int &l) const
{
	for (int i = 0; i < length; i++)
		if (data[i] == e) {
			l = i;
			return true;
		}
	return false;
}

template<typename T>
bool LinearList<T>::ListInsert(int i, T e)
{
	if (ListFull() || i<0 || i>length)
		return false;
	else
		for (int j = length - 1; j >= i; j--)
			data[j] = data[j - 1];
	data[i] = e;
	length += 1;
	return true;
}

template<typename T>
bool LinearList<T>::ListDelete(int i, T &e)
{
	if (ListEmpty() || i<0 || i>length - 1)
		return false;
	else {
		e = data[i];
		for (int j = i; j < length - 1; j++)
			data[j] = data[j + 1];
	}
	length -= 1;
}

template<typename T>
const int LinearList<T>::ListLength()
{
	return length;
}

template<typename T>
void LinearList<T>::show() const
{
	for (int i = 0; i < length; i++)
		cout << data[i];
	cout << endl;
}

template<typename T>
LinearList<T> & LinearList<T>::operator=(const LinearList<T> & lt)
{
	for (int i = 0; i < lt.length; i++)
		data[i] = lt.data[i];
	length = lt.length;
	return *this;
}

template<typename T>
LinearList<T> &LinearList<T>::operator+(const LinearList<T> & lt1)
{
	int j,k;
	for (j = length,k=0; j < length + lt1.length; j++,k++)
		data[j] = lt1.data[k];
	length = length + lt1.length;
	return *this;
}
 
#endif // !LINEARLIST
