#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct Node{
	int data;
	struct Node *next;
}Node;

void init(Node *&s)
{
	s = (Node *)malloc(sizeof(Node));
	s->next = NULL;
}
int isEmpty(Node *s)
{
	if (s->next == NULL)return 1;
	else return 0;
}
void push(Node *s, int x)
{
	Node *p;
	p = (Node*)malloc(sizeof(Node));
	p->next = NULL;
	p->data = x;
	p->next = s->next;
	s->next = p;
}
int pop(Node *s, int &x)
{
	Node *p;
	if (isEmpty(s))return 0;
	p = s->next;
	x = p->data;
	s->next = p->next;
	free(p);
	return 1;
}