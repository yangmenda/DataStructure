#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct Node {
	char data;
	int ltag, rtag;
	struct Node *lchild;
	struct Node *rchild;
}Node;
void visit(Node *p)
{
	cout << p->data << endl;
}
void inThread(Node *p, Node *&pre)
{
	if (p != NULL)
	{
		inThread(p->lchild, pre);	//�ݹ�ʹ����������
		if (p->lchild == NULL)	//��p�ڵ���ָ��Ϊ��
		{
			p->lchild = pre;	//����ָ��ǰ���ڵ�
			p->ltag = 1;	//tag��Ϊ1
		}
		if (pre != NULL && pre->rchild == NULL)	//��ǰ���ڵ���ָ��Ϊ��
		{
			pre->rchild = p;	//����ָ���̽ڵ�
			pre->rtag = 1;
		}
		pre = p;	//preָ��ָ��ǰ�ڵ�
		p = p->rchild;	//pָ��ָ��ǰ�ڵ��������
		inThread(p, pre);	//��������
	}
}
void preThread(Node *p, Node *&pre)
{
	if (p != NULL)
	{
		if (p->lchild == NULL)
		{
			p->lchild = pre;
			p->ltag = 1;
		}
		if (pre != NULL && pre->rchild == NULL)
		{
			pre->rchild = p;
			pre->rtag = 1;
		}
		pre = p;
		if (p->ltag == 0)
			preThread(p->lchild, pre);
		if (p->rtag == 0)
			preThread(p->rchild, pre);
		
	}
}
void postThread(Node *p, Node*&pre)
{
	if (p != NULL)
	{
		postThread(p->lchild, pre);
		postThread(p->rchild, pre);
		if (p->lchild == NULL)
		{
			p->lchild = pre;
			p->ltag = 1;
		}
		if (pre != NULL && pre->rchild)
		{
			pre->rchild = p;
			pre->rtag = 1;
		}
		pre = p;
	}
	

}
void createInThread(Node *root)
{
	Node *pre = NULL;
	if (root != NULL)
	{
		inThread(root, pre);
		pre->rchild = NULL;
		pre->rtag = 1;
	}
}
Node *First(Node *p)
{
	while (p->ltag == 0)
		p = p->lchild;
	return p;
}
Node *next(Node *p)
{
	if (p->rtag == 0)
		return First(p->rchild);
	else
		return p->rchild;
}
void InOrder(Node *root)
{
	for (Node *p = First(root); p != NULL; p = next(p))
		visit(p);

}
void preOrder(Node *root)
{
	if (root != NULL)
	{
		Node *p = root;
		while (p!=NULL)
		{
			while (p->ltag == 0)
			{
				visit(p);
				p = p->lchild;
			}
			visit(p);
			p = p->rchild;
		}
	}
}
Node* isLast(Node *t)
{
	Node *p = t;
	while (p && !p->rtag)
		p = p->rchild;
	return p;
}
Node* InPrior(Node *t)
{
	Node *p = t->lchild;
	if (p && !p->ltag)
		p = isLast(p);
	return p;
}