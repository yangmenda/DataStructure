#include<iostream>
using namespace std;
void sift(int r[], int low, int high)
{
	int i = low, j = 2 * i;
	int temp = r[i];
	while (j <= high)
	{
		if (j < high&&r[j] < r[j + 1])	//如果右节点比左节点大，则指向右节点
			++j;
		if (temp < r[j])	//若指向的这个值比根节点值大
		{
			r[i] = r[j];	//将此节点数值与根节点数值交换
			i = j;	//i重定向至交换位置
			j = 2 * i;	//j指向交换位置的子孙节点
		}
		else break;

	}
	r[i] = temp;	//将值放到合适位置上
}
void HeapSort(int r[], int n)
{
	int i, temp;
	for (i = n / 2; i >= 1; --i)
		sift(r, i, n);
	for (i = n; i >= 2; --i)
	{
		temp = r[1];
		r[1] = r[i];
		r[i] = temp;
		sift(r, 1, i - 1);
	}
}