#include<iostream>
#include<algorithm>
using namespace std;
void Bubble(int r[], int n)
{
	int i, j, flag;
	for (i = n - 1; i >= 1; --i)	//一趟排序后，因为 最大值已经在最后，所以代排数组长度减一
	{
		flag = 0;
		for (j = 1; j <= i; ++j)	//j是待排数组的头
		{
			if (r[j - 1] > r[j])
			{
				swap(r[j - 1], r[j]);
				flag = 1;
			}
		}
		if (flag == 0)return;
	}
}
void double_sort(int a[], int n)
{
	int right = n - 1;
	int left = 0;
	bool flag = true;
	int i, j;
	while (flag)
	{
		flag = false;
		for (i = left; i < right; ++i)
		{
			if (a[i] > a[i + 1])
			{
				swap(a[i], a[i + 1]);
				flag = true;
			}
			

		}
		--right;
		for (j = right; j > left; --j)
		{
			if (a[j] < a[j - 1])
			{
				swap(a[j], a[j - 1]);
				flag = true;
			}
		}
		++left;
	}
}