#include<iostream>
using namespace std;
void sift(int r[], int low, int high)
{
	int i = low, j = 2 * i;
	int temp = r[i];
	while (j <= high)
	{
		if (j < high&&r[j] < r[j + 1])	//����ҽڵ����ڵ����ָ���ҽڵ�
			++j;
		if (temp < r[j])	//��ָ������ֵ�ȸ��ڵ�ֵ��
		{
			r[i] = r[j];	//���˽ڵ���ֵ����ڵ���ֵ����
			i = j;	//i�ض���������λ��
			j = 2 * i;	//jָ�򽻻�λ�õ�����ڵ�
		}
		else break;

	}
	r[i] = temp;	//��ֵ�ŵ�����λ����
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