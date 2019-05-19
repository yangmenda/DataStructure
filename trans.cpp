#include<iostream>
using namespace std;

int BaseTrans(int n)
{
	int i, result = 0;
	int stack[50], top = -1;
	while (n != 0)
	{
		i = n % 2;
		n = n / 2;
		stack[++top] = i;
	}
	while (top != -1)
	{
		i = stack[top];
		--top;
		result = result * 10 + i;

	}
	return result;
}
int main()
{
	int n = 10;
	int r;
	r = BaseTrans(n);
	cout << r << endl;
}