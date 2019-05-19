#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct Node {
	char data;
	struct Node *parent;
	struct Node *lchild;
	struct Node *rchild;
}Node;
void init(Node *p, Node *q)
{
	if (p != NULL)
	{
		p->parent = q;
		q = p;
		init(p->lchild, q);
		init(p->rchild, q);
	}
}
void printPath(Node *p)
{
	while (p != NULL)
	{
		cout << p->data << " " << endl;
		p = p->parent;
	}
}
void printAllPath(Node *p)
{
	if (p != NULL)
	{
		printPath(p);
		printAllPath(p->lchild);
		printAllPath(p->rchild);

	}
}