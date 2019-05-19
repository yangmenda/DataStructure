#include<iostream>
#include<stdlib.h>
using namespace std;
#define maxsize 500
typedef struct Node {
	int val;
	struct Node *lchild;
	struct Node *rchild;
}Node;
int visit(Node *p)
{
	cout << p->val << endl;
}
void link(Node *p, Node *&head, Node *&tail)
{
	if (p != NULL)
	{
		if (p->lchild == NULL && p->rchild == NULL)
		{
			if (head == NULL)
			{
				head = p;
				tail = p;
			}
			else
			{
				tail->rchild = p;
				tail = p;
			}
		}
		link(p->lchild, head, tail);
		link(p->rchild, head, tail);
	}
}
void change(char pre[], int l1, int r1, char post[], int l2, int r2)
{
	if (l1 <= r1)
	{
		post[r2] = pre[l1];
		change(pre, l1 + 1, (l1 + 1 + r1) / 2, post, l2, (l2 + r2 - 1) / 2);
		change(pre, (l1 + 1 + r1) / 2+1, r1, post, (l2 + r2 - 1) / 2+1, r2-1);
	}
}
void leno(Node *p,int x)
{
	int l = 1;
	if (p != NULL)
	{
		if (p->val = x)
		{
			cout << l << endl;
		}
		++l;
		leno(p->lchild, x);
		leno(p->rchild, x);
		--l;

	}
}
void doubleSort(Node *p)
{
	if (p != NULL)
	{
		visit(p);
		doubleSort(p->lchild);
		visit(p);
		doubleSort(p->rchild);
	}
}
void allPath(Node *p)
{
	int i, top = 0;
	char pathstack[maxsize];
	if (p != NULL)
	{
		pathstack[top] = p->val;
		++top;
		if (p->lchild == NULL && p->rchild == NULL)
		{
			for (i = 0; i < top; ++i)
			{
				cout << pathstack[i];
			}
		}
		allPath(p->lchild);
		allPath(p->rchild);
		--top;
	}
}