#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
	int data;
	struct Node *pre;
	struct Node *next;
};

void create(Node *&l, int a[], int n)
{
	Node *s, *r;
	int i;
	l = (Node*)malloc(sizeof(Node));
	l->next = NULL;
	r = l;
	for (i = 0; i < n; ++i)
	{
		s= (Node*)malloc(sizeof(Node));
		s->data = a[i];
		r->next = s;
		s->pre = r;
		r = s;
	}
	r->next = NULL;
}
Node* find(Node *c, int x)
{
	Node *p = c->next;
	while (p != NULL)
	{
		if (p->data = x)
			break;
		p = p->next;
	}
	return p;  
}