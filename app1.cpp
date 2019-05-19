#include<iostream>
#include<stdlib.h>
using namespace std;
#define maxsize 1000
typedef struct Node {
	int val;
	struct Node *lchild;
	struct Node *rchild;
}Node;
typedef struct {
	Node *p;
	int lno;
}St;
int visit(Node *p)
{
	cout << p->val << endl;
}
int Op(int a, int b, char c)
{
	switch (c)
	{
	case '+': return a + b; break;
	case '-': return a - b; break;
	case '*': return a * b; break;
	case '/': if (b == 0)break;
			  else {
					return a / b; break;
				}
	default:return 0;
	}
		
		
}
int comp(Node *p)
{
	int a, b;
	if (p!= NULL)
	{
		if (p->lchild != NULL && p->rchild != NULL)
		{
			a=comp(p->lchild);
			b=comp(p->rchild);
			return Op(a, b, p->val);
		}
		else
		{
			return p->val - '0';
		}
	}
	
	else return 0;
}
int getDepth(Node *p)
{
	int LD, RD;
	if (p == NULL)
		return 0;
	else
	{
		LD = getDepth(p->lchild);	//求左子树深度
		RD = getDepth(p->rchild);	//求右子树深度
		return (LD > RD ? LD : RD) + 1;	//取出左子树和右子树深度最大的那一个加一
	}
}
void search(Node *a, Node *&b, int x)
{
	if (a!= NULL)
	{
		if (a->val == x)
		{
			b = a;
		}
		else
		{
			search(a->lchild, b, x);
			search(a->rchild, b, x);
		}
	}
}
void trave(Node *p, int k)
{
	int n = 0;
	if (p != NULL)
	{
		++n;
		if (n == k)
		{
			cout << p->val << endl;
		}
		trave(p->lchild, k);
		trave(p->rchild, k);

	}
}
void level(Node *p)
{
	int front, rear;
	Node *que[maxsize];
	front = rear = 0;
	Node *q;
	if (p != NULL)
	{
		rear = (rear + 1) % maxsize;	//根节点入队
		que[rear] = p;
		while (front != rear)
		{
			front = (front + 1) % maxsize;	//根节点入队
			q = que[front];
			visit(q);
			if (q->lchild != NULL)	//左子树不为空，则左子树根节点入队
			{
				rear = (rear + 1) % maxsize;
				que[rear] = q->lchild;
			}
			if (q->rchild != NULL)	//右子树不为空，则右子树根节点入队
			{
				rear = (rear + 1) % maxsize;
				que[rear] = q->rchild;

			}
		}
	}
}
int findMax(Node *b)
{
	St que[maxsize];
	int front, rear, lno, i, j,n, max,Lno;
	front = rear = 0;
	Node *q;
	if (b != NULL)
	{
		++rear;
		que[rear].p = b;
		que[rear].lno = 1;
		while (front != rear)
		{
			++front;
			q = que[front].p;
			Lno = que[front].lno;
			if (q->lchild != NULL)	//左子树不为空，则左子树根节点入队
			{
				++rear;
				que[rear].p = q->lchild;
				que[rear].lno = Lno + 1;

			}
			if (q->rchild != NULL)	//左子树不为空，则左子树根节点入队
			{
				++rear;
				que[rear].p = q->rchild;
				que[rear].lno = Lno + 1;

			}
			
			
		}
		max = 0;
		for (i = 0; i <= Lno; ++i)
		{
			n = 0;
			for (j = 1; j <= rear; ++j)
			{
				if (que[j].lno == i)++n;
				if (max < n)max = n;
			}
		}
		return n;
	}
	else return 0;
}