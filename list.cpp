#include <iostream>
#include <stdlib.h>
using namespace std;


struct LNode {
	int data;
	struct LNode *next;
};
void merge(LNode *a, LNode *b, LNode *&c)
{
	LNode *p = a->next;
	LNode *q = b->next;
	LNode *r;
	c = a;
	c->next = NULL;
	free(b);
	r = c;
	while (p != NULL && q != NULL)
	{
		if (p->data <= q->data)
		{
			r->next = p; p = p->next;
			r = r->next;
		}
		else {
			r->next = q; q = q->next;
			r = r->next;
		}
	}
	r->next = NULL;
	if (p != NULL)r->next = p;
	if (q != NULL)r->next = q;
}
void createList_A(LNode *&c, int a[], int n)
{
	LNode *s, *r;
	int i;
	c = (LNode*)malloc(sizeof(LNode));
	c->next = NULL;
	r = c;
	for (i = 0; i < n; ++i)
	{
		s = (LNode *)malloc(sizeof(LNode));
		s->data = a[i];
		r->next = s;
		r->next = r;
	}
	r->next = NULL;
}
void createList_B(LNode *&c, int a[], int n)
{
	LNode *s;
	int i;
	c = (LNode*)malloc(sizeof(LNode));
	c->next = NULL;
	
	for (i = 0; i < n; ++i)
	{
		s= (LNode*)malloc(sizeof(LNode));
		s->data = a[i];
		s->next = c->next;
		c->next = s;
	}
}
int FindAndDelete(LNode *c, int x)
{
	LNode *p, *q;
	p = c;
	while (p->next != NULL)
	{
		if (p->next->data == x)
			break;
		p = p->next;
	}
	if (p->next == NULL)
	{
		return 0;
	}
	else {
		q = p->next;
		p->next = p->next->next;
		free(q);
		return 1;
	}
}