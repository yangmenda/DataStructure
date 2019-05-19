#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node {
	int data;
	struct Node *next;
};
void deleteSame(Node *n)
{
	Node *p = n->next;
	Node *q;
	while (p->next != NULL)
	{
		if (p->data == p->next->data)
		{
			q = p->next;
			p->next = p->next->next;
			free(q);
		}
		else {
			p = p->next;
		}
	}
}
void DeleteMin(Node *n)
{
	Node *p,*minp, *s;
	p = n->next;
	minp = n;
	while (p->next != NULL)
	{
		if (p->next->data < minp->next->data)
		{
			minp = p;
			p = p->next;
		}
		else {
			p = p->next;
		}
	}
	s = minp->next;
	p->next = minp->next->next;
	free(s);
}
void reverse(Node *n)
{
	Node *p = n->next,*q;
	n->next = NULL;
	while (p->next != NULL)
	{
		q = p->next;
		p->next = n->next;
		n->next = p;
		p = q;

	}
}
void divide(Node *a,Node *&b)
{
	Node *p, *q, *r;
	b = (Node *)malloc(sizeof(Node));
	b->next = NULL;
	r = b;
	p = a;
	while (p->next != NULL)
	{
		if (p->next->data % 2 == 0)
		{
			q = p->next;		//���˵�ָ���ݴ�
			p->next = q->next;	//������ɾ���˵�
			q->next = NULL;		//��ȡ�������һ�����ÿգ��������������
			r->next = q;		//����������

		}
		else {
			p = p->next;
		}
	}

}
int findK(Node *head, int k)
{
	Node *p1 = head->next;
	Node *p = head;
	int i = 1;
	while (p1!=NULL)
	{
		p1 = p1->next;
		++i;
		if (i > k)p = p->next;
	}
	if (p == head) return 0;
	else {
		cout << p->data;
		return 1;
	}
}