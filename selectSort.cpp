#include<iostream>
using namespace std;
void selectSort(int r[], int n)
{
	int i, j, k, temp;
	for (i = 0; i < n; ++i)
	{
		k = i;
		for (j = i + 1; j < n; ++j)
		{
			if (r[k] > r[j])
				k = j;
		}
		temp = r[i];
		r[i] = r[k];
		r[k] = temp;
	}
}