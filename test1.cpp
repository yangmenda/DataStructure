#include<iostream>
#include<algorithm>
using namespace std;

int Length(int a[])
{
	return sizeof(a) / sizeof(a[0]);
}
void Reverse(int l[])
{
	int i, j;
	
	int length = sizeof(l) / sizeof(l[0]);
	for (i = 0, j = length-1; i < j; ++i, --j)
	{
		swap(l[i], l[j]);

	}
}
void Delete(int a[], int i, int j)
{
	int k, p;
	int length = sizeof(a) / sizeof(a[0]);
	p = j - i + 1;
	for (k = i + 1; k < length; ++k)
	{
		a[k - p] = a[p];
	}
	length -= p;
}
void Alter(int a[])
{
	int i = 0;
	int j = Length(a) - 1;
	int temp = a[i];
	while(i<j)
	{
		while (i<j&&a[j]>temp)j--;
		if (i < j)
		{
			a[i] = a[j];
			++i;
		}
		while (i < j&&a[i] < temp)i++;
		if (i < j)
		{
			a[j] = a[i];
			--j;
		}
	}
	
}
void findMin(int a[], int &i)
{
	i = a[0];
	while (i / 10 <= n - 1)
	{
		if (i % 10 > a[i / 10])
		{

		}
	}
}
int main()
{
	int l[5] = { 1,2,3,4,5 };
	
	
	for (int i = 0; i < 5; ++i)
	{
		cout << l[i] << endl;
	}
}