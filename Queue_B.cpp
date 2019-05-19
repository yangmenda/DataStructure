#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct {
	int data;
	struct Node *next;
}Node;
typedef struct {
	Node *front;
	Node *rear;

}Queue;
void init(Queue *&q)
{
	q = (Queue *)malloc(sizeof(Queue));
	q->front = q->rear = 0;
}
int isEmpty(Queue *q)
{
	if (q->front == NULL || q->rear == NULL)
		return 1;
	else return 0;
}
void Enqueue(Queue *q, int &x)
{
	Node *p;
	p = (Node*)malloc(sizeof(Node));
	p->data = x;
	p->next = NULL;
	if (q->rear == NULL)q->front = q->rear = p;
	else {
		q->rear->next = p;
		q->rear = p;
	}


}
int Dequeue(Queue *&q)
{
	Node *p;
	if (q->rear == NULL)
		return 0;
	else
		p = q->front;
	if (q->front == q->rear)
		q->front = q->rear = NULL;
	else
	{
		q->front = q->front->next;
		
	}
	int x = p->data;
	free(p);
	return 1;
}