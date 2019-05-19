#include <iostream>
using namespace std;

#define maxsize 6
void create(int a[][maxsize], int m, int n, int b[][3])
{
	int i, j, k = 1;
	for (i = 0; i < m; ++i)
		for (j = 0; j < n; ++j)
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
int search(int b[][3], int x)
{
	int i, t;
	t = b[0][0];
	i = 1;
	while (i <= t && b[i][0] != x)
		i++;
	if (i <= t)return 1;
	else return 0;
}
void transpose(int a[][3], int b[][3])
{
	int p, q, col;
	b[0][0] = a[0][0];
	b[0][1] = a[0][2];
	b[0][2] = a[0][1];
	if (b[0][0] > 0) {
		q = 1;
		for(col=0;col<b[0][1];++col)
			for(p=1;p<b[0][0];++p)
				if (a[p][2] == col)
				{
					b[q][0] = a[p][0];
					b[q][1] = a[p][2];
					b[q][2] = a[p][1];
					++q;
				}
	}
}