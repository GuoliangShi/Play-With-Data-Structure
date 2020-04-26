#pragma once
#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Expression
{
private:
	string data;
	string trans_data;
	int result;
public:
	Expression() {};
	Expression(string &s) { data = s; }
	void Transfer();
	void ResetData(string &s);
	void Calculate();
	int Result() { return result; }
	string & Trans_result() { return trans_data; }
};

void Expression::ResetData(string &s)
{
	data = s;
}

void Expression::Transfer()
{
	stack<char> temp;
	for (int i = 0; i < data.size(); i++) {
		while (isalnum(data[i])) {
			trans_data += data[i];
			i++;
		}
		trans_data += ' ';
		if (data[i] == '(')
			temp.push('(');
		else if (data[i] == ')') {
			while (temp.top() != '(') {
				trans_data += temp.top();
				temp.pop();
			}
			temp.pop();
		}
		else {
			while (!temp.empty() && (temp.top() == '*' || temp.top() == '/')) {
				trans_data += temp.top();
				temp.pop();
			}
			while (!temp.empty() && (temp.top() == '+' || temp.top() == '-') &&
				(data[i] == '+' || data[i] == '-'))
			{
				trans_data += temp.top();
				temp.pop();
			}
			temp.push(data[i]);
		}
	}
	while (!temp.empty()) {
		trans_data += temp.top();
		temp.pop();
	}
}


void Expression::Calculate()
{
	stack<int> temp;
	for (int i = 0; i < trans_data.size(); i++) {
		//cout << i << ": " << trans_data[i] << endl;
		if (trans_data[i] == ' ')
			continue;
		else if (isalnum(trans_data[i])) {
			int num = 0;
			while (isalnum(trans_data[i])) {
				num = num * 10 + (trans_data[i]-'0');
				i++;
			}
			i--;
			temp.push(num);
		}
		else {
			int a, b;
			switch (trans_data[i])
			{
			case '+':
				a = temp.top();
				temp.pop();
				b = a + temp.top();
				temp.pop();
				temp.push(b);
				break;
			case '-':
				a = temp.top();
				temp.pop();
				b = temp.top() - a;
				temp.pop();
				temp.push(b);
				break;
			case'*':
				a = temp.top();
				temp.pop();
				b = temp.top() * a;
				temp.pop();
				temp.push(b);
				break;
			case '/':
				a = temp.top();
				temp.pop();
				b = temp.top() / a;
				temp.pop();
				temp.push(b);
				break;
			default:
				break;
			}
		}
		
	}
	result = temp.top();
}

#endif // !EXPRESSION
