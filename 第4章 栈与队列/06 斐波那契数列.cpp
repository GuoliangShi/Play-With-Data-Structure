#include<iostream>

using namespace std;

int Fbl(int i)
{
	if (i < 2)
		return i == 0 ? 0 : 1;
	return Fbl(i - 2) + Fbl(i - 1);
}

void main()
{
	for (int i = 0; i < 10; i++)
		cout << i << "# " << Fbl(i) << endl;
}
