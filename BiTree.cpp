#include<iostream>
#include<stdlib.h>
using namespace std;
#define maxsize 500
typedef struct Node{
	int val;
	struct Node *lchild;
	struct Node *rchild;
}Node;
 typedef struct {
	int data[maxsize];
	int top;
}Stack;
int visit(Node *p)
{
	cout << p->val << endl;
}
void preOrder(Node *p)
{
	if (p != NULL)
	{
		visit(p);
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}
void inOrder(Node *p)
{
	if (p != NULL)
	{
		inOrder(p->lchild);
		visit(p);
		inOrder(p->rchild);
	}
}
void postOrder(Node *p)
{
	if (p != NULL)
	{
		postOrder(p->lchild);
		postOrder(p->rchild);
		visit(p);
	}
}
void preOrder_NoRe(Node *bt)
{
	if (bt != NULL)
	{
		Node *stack[maxsize];
		int top = -1;
		Node *p;
		stack[++top] = bt;
		while (top!=-1)
		{
			p = stack[top--];
			visit(p);
			if (p->rchild != NULL)
				stack[++top] = p->rchild;
			if (p->lchild != NULL)
				stack[++top] = p->lchild;
		}
	}
}
void inOrder_noRe(Node *bt)
{
	if (bt != NULL)
	{
		Node *stack[maxsize];
		int top = -1;
		Node *p;
		p = bt;
		while (top != -1 || p != NULL)
		{
			while (p != NULL)
			{
				stack[++top] = p;
				p = p->lchild;
			}
			if (top != -1)
			{
				p = stack[top--];
				visit(p);
				p = p->rchild;
			}
		}
	}
}
void posOrder_noRe(Node *bt)
{
	if (!bt)
	{
		Node *stack1[maxsize]; int top1 = -1;
		Node *stack2[maxsize]; int top2 = -1;
		Node *p;
		stack1[++top1] = bt;
		while (top1 != -1)
		{
			p = stack1[top1--];
			stack2[++top2] = p;
			if (p->lchild != NULL)
				stack1[++top1] = p->lchild;
			if (p->rchild != NULL)
				stack1[++top1] = p->rchild;
		}
		while (top2 != NULL) {
			p = stack2[top2--];
			visit(p);
		}
	}
}
int count(Node *p)
{
	int n1, n2;
	if (p == NULL)
		return 0;
	else if (p->lchild == NULL && p->rchild == NULL)return 1;
	else {
		n1 = count(p->lchild);
		n2 = count(p->rchild);
		return n1 + n2;
	}
}