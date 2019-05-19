#include<iostream>
using namespace std;
void quickSort(int r[], int low, int high)
{
	int i = low, j = high;
	int temp;
	if(low < high)
	{
		temp = r[low];
		while (i < j)
		{
			while (j > i&&r[j] >= temp)--j;
			if (i < j)
			{
				r[i] = r[j];
				++i;
			}
			while (i < j&&r[i] < temp)++i;
			if (i < j)
			{
				r[j] = r[i];
				--j;
			}
		}
		r[i] = temp;
		quickSort(r, low, i - 1);
		quickSort(r, i + 1, high);
	}
}