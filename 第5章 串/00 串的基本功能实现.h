#pragma once
#ifndef STRINGV1_H_
#define STRINGV1_H_

#include<iostream>
#include<string>

using namespace std;

class Stringv1
{
private:
	string data;
	int length;
public:
	Stringv1() { length = 0; }
	Stringv1(const Stringv1 & s);
	Stringv1(const char *c);
	Stringv1 &operator=(const Stringv1 & s);
	void Show() const;
	bool ClearString();
	bool isEmpty() const { return (length == 0); }
	int Length() const { return length; }
	string SubString(int pos, int len);
	int Index(const string & s, const int pos);
	int Replace(const string & s1, const string & s2);
	string StrInsert(const string & s1, int pos);

	friend int StrCompare(const Stringv1 & s1, const Stringv1 & s2);
	friend Stringv1 Concat(const Stringv1 & s1, const Stringv1 & s2);
};

Stringv1::Stringv1(const Stringv1 & s)
{
	data = s.data;
	length = s.length;
}

Stringv1::Stringv1(const char *c)
{
	length = strlen(c);
	for (int i = 0; i < length; i++)
		data.push_back(c[i]);
}

Stringv1 &Stringv1::operator=(const Stringv1 & s)
{
	data = s.data;
	length = s.length;
	return *this;
}

void Stringv1::Show() const
{
	cout << data << endl;
	cout << "has " << length << " charater.\n";
}

bool Stringv1::ClearString()
{
	length = 0;
	data.clear();
	return true;
}

int StrCompare(const Stringv1 & s1, const Stringv1 & s2)
{
	if (s1.data.size() == 0 || s2.data.size() == 0) {
		cout << "Least an object is null.\n";
		exit(EXIT_FAILURE);
	}
	else {
		int i = 0;
		while (i<s1.data.size()&&i<s2.data.size()&&
				s1.data[i] == s2.data[i]) {
			i++;
		}
		if (i == s1.data.size() && i == s2.data.size())
			return 0;
		else
			return (s1.data[i] < s2.data[i]) ? -1 : 1;
	}
}

Stringv1 Concat(const Stringv1 & s1, const Stringv1 & s2)
{
	Stringv1 con;
	con.data = s1.data + s2.data;
	con.length = s1.length + s2.length;
	return con;
}

string Stringv1::SubString(int pos, int len)
{
	string out;
	if (pos + len > length) {
		cout << "The substring is too long!\n";
		exit(EXIT_FAILURE);
	}
	else
		for (int i = 0; i < len; i++)
			out.push_back(data[pos + i]);
	return out;
}

int Stringv1::Index(const string & s, const int pos)
{
	if (s.empty()) {
		cout << "is empty!\n";
		return 0;
	}

	for (int i = pos; i < length; i++) {
		int j = 0;
		while (j < s.size() && i < length&&s[j] != data[i])
			i++;
		int temp = i;
		while (j < s.size() && i < length&&s[j] == data[i]) {
			i++; j++;
		}
		if (j == s.size())
			return temp;
		else
			i = temp + 1;
	}

	return 0;
}

int Stringv1::Replace(const string & s1, const string & s2)
{
	if (s1.size() != s2.size()) {
		cout << "Must have same length!\n";
		return 0;
	}
	int time = 0;
	for (int i = 0; i < length; ) {
		int  index = Index(s1, i);
		if (index) {
			for (char temp : s2) {
				data[index] = temp;
				index++;
			}
			time++;
			i = index + 1;
		}
		else if (index == 0)
			return time;
	}
}

string Stringv1::StrInsert(const string & s1, int pos)
{
	if (s1.size() == 0)
		cout << "The string is empty!\n";
	if (pos > length)
		cout << "The index is out of range!\n";
	return this->SubString(0, pos - 1) + s1 +
		this->SubString(pos - 1, length - pos + 1);
}


#endif // !STRINGV1_H_
