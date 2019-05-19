#include <iostream>
#include <stdlib.h>
using namespace std;
#define maxsize 50
typedef struct {
	int row, col;
	struct OLNode *right, *down;
	float val;
}OLNode;
typedef struct {
	OLNode *rhead, *chead;
	int m, n, k;
}CrossList;

int create(int a[][maxsize], int m, int n, int k,CrossList &c)
{
	if (c.chead)
		free(c.chead);
	if (c.rhead)
		free(c.rhead);
	c.m = m;
	c.n = n;
	c.k = k;
	if (!(c.chead = (OLNode*)malloc(sizeof(OLNode)*m)))
		return 0;
	if (!(c.rhead = (OLNode*)malloc(sizeof(OLNode)*n)))
		return 0;
	for (int i = 0; i < m; ++i)
	{
		c.chead[i].right = NULL;
		c.chead[i].down = NULL;
	}
	for (int j = 0; j < n; ++j)
	{
		c.rhead[j].right = NULL;
		c.rhead[j].down = NULL;
	}
	OLNode *temp_c[maxsize];
	for (int k = 0; k < n; ++k)
		temp_c[k] = &(c.rhead[k]);
	for (int i = 0; i < m; ++i)
	{
		OLNode *r = &(c.chead[i]);
			for (int j = 0; j < n; ++j)
			{
				if(a[i][j]!=0)
				{
					OLNode *p = (OLNode*)malloc(sizeof(OLNode));
					p->row = i;
					p->col = j;
					p->val = a[i][j];
					p->down = NULL;
					p->right = NULL;
					r->right = p;
					r = p;
					temp_c[j]->down=p;
					temp_c[j] = p;
			}
		}
	}
	return 1;
}