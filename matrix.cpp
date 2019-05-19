#include <iostream>
using namespace std;

#define maxsize 6

void trans(int a[][maxsize], int b[][maxsize],int m, int n)
{
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			b[j][i] = a[i][j];
}
void addm(int c[][maxsize],int a[][maxsize], int b[][maxsize], int m, int n)
{
	
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			 c[i][j]=b[j][i] + a[i][j];
}
void multiply(int c[][maxsize], int a[][maxsize], int b[][maxsize], int m, int n,int k)
{
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < k; ++j)
		{
			c[i][j] = 0;
			for (int h = 0; h < k; ++h)
			{
				c[i][j] += a[i][h] * b[h][j];
			}
		}
	
}
void createTrimat(float a[][maxsize], int m, int n, float b[][3])
{
	int k = 1;
	for(int i=0;i<m;++i)
		for (int j = 0; j < n; ++j)
		{
			if (a[i][j] != 0)
			{
				b[k][0] = a[i][j];
				b[k][1] = i;
				b[k][2] = j;
				++k;
			}
			b[0][0] = k - 1;
			b[0][1] = m;
			b[0][2] = n;
		}
}
void printMin(int a[][maxsize], int m, int n)
{
	int i, j, k, min, minj;
	int flag;
	for (i = 0; i < m; ++i)
	{
		min = a[i][0];
		minj = 0;
		for(j=1;j<n;++j)
			if (a[i][j] < min)
			{
				min = a[i][j];
				minj = j;
			}
		flag = 1;
		for(k = 0; k < m;++k)
			if (min > a[k][minj])
			{
				flag = 0;
				break;
				
			}
		if (flag)
			cout << min << ",[" << i << "," << minj << "]" << " ";
	}
	cout << endl;
}
void printMax(int a[][maxsize], int m, int n)
{
	int i=0, j, k, max, maxj;
	int flag;
	for (i = 0; i < m; ++i)
	{
		max = a[i][0];
		maxj = 0;
		for (j = 1; j < n; ++j)
		{
			if (a[i][j] > max)
			{
				max = a[i][j];
				maxj = j;
			}
			flag = 1;
			for (k = 0; k < m; ++k)
				if (a[k][maxj])
				{
					flag = 0;
					break;

				}
			if (flag)
				cout << max << ",[" << i << "," << maxj << "]" << " ";

		}
	}
}
