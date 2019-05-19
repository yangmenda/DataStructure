#include<iostream>
#include <algorithm>
using namespace std;
void Move(int a[], int n)
{
	int i = -1, j;
	for (j = 0; j < n; ++j)
	{
		if (a[j] != 0)
		{
			++i;	//标识符i指向将要替换的0的数组位置
			if (i != j)		//如果两个标识符没指向一处，则交换位置数据
			{
				swap(a[i], a[j]);
			}
		}
	}
}
float findMax(float a[], int i, int j)
{
	float max;
	if (i == j)
	{
		return a[i];
	}
	else {
		max = findMax(a, i + 1, j);
		if (a[i] > max)return a[i];
		else return max;
	}
}
float arraySum(float a[], int i, int j)
{
	if (i == j)return a[i];
	else
	{
		return a[i] + arraySum(a, i + 1, j);
	}
}
float arrayAverage(float a[], int i, int j)
{
	if (i == j)return a[i];
	else {
		return (a[i] + a[j - 1] * arrayAverage(a, i + 1, j)) / (j - i + 1);
	}
}
void divide(int a[], int n)
{
	int i = 0, j = n - 1, temp;
	while (i < j)
	{
		while (a[i] % 2 == 1 && i < j)
			++i;
		while (a[j] % 2 == 0 && i < j)
			++j;
		if (i < j)
		{
			swap(a[i], a[j]);
			++i;
			--j;
		}
	}
}
void divide2(int a[], int n)
{
	int i = 0, j = n-1;
	swap(a[i], a[j]);
	int x = a[i];
	while (i != j)
	{
		while (j > i&&a[j] > x)--j;
		if (i < j)
		{
			a[i] = a[j];
			++i;
		}
		while (i < j&&a[i] < x)++i;
		if (i < j)
		{
			a[j] = a[i];
			--j;
		}
		a[i] = x;
	}
}
int main()
{
	int a[8] = { 1,2,3,4,5,6,7,8 };
	divide(a, 8);
	for (int i = 0; i < 8; ++i)
	{
		cout << a[i] << " ";
	}
}