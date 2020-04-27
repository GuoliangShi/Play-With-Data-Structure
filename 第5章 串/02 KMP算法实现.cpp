#include<iostream>
#include<string>

using namespace std;

int Index(string s1, string s2, int pos);
void Next(const string &s1, int *next);
int Index_KMP(const string s1, const string s2, int pos);

void main()
{
	string s1 = "vdasvfsevbqeavb";
	string s2 = "bqe";
	cout << Index(s1, s2, 0) << endl;
	cout << Index_KMP(s1, s2, 0) << endl;
}

void Next(const string &s1, int *next)
{
	next[0] = 0; next[1] = 0;
	int i, j = 0;
	for (i = 2; i < s1.size(); i++) {
		if (s1[i - 1] == s1[j]) {
			j++;
			next[i] = j;
		}
		else {
			j = 0;
			next[i] = j;
		}
	}
}

int Index_KMP(const string s1, const string s2, int pos)
{
	int *next = new int[s2.size()];
	Next(s2, next);
	int i = pos;
	int j = 0;
	while (i < s1.size() && j < s2.size()) {
		if (s1[i] == s2[j]) {
			i++; j++;
		}
		else
		{
			if (j == 0)i++;
			j = next[j];
		}
	}
	delete[] next;
	if (j == s2.size())
		return (i - j);
	else
		return 0;
}

int Index(string s1, string s2, int pos)
{
	int i = pos;
	int j = 0;
	while (i < s1.size() && j < s2.size()) {
		if (s1[i] == s2[j]) {
			i++; j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j == s2.size())
		return (i - j);
	else
		return 0;
}
