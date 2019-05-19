#include <iostream>
using namespace std;
void Resort(int r[], int n)
{
	int i = 0, j = n - 1;
	int temp;
	while (i < j)
	{
		while (i < j&&r[i] < 0)++i;
		temp = r[i];
		while (i < j&&r[j]>0)--j;
		r[i++] = r[j];
		r[j--] = temp;
	}
}
void sort(int a[], int b[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		b[a[i]] = a[i];
	}
}
void countSort(int a[], int b[], int n)
{
	int i, j, count;
	for (i = 0; i < n; ++i)
	{
		count = 0;
		for (j = 0; j < n; ++j)
		{
			if (a[i] > a[j])
				++count;

		}
		b[count] = a[i];
	}
}