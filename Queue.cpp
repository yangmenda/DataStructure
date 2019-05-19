#include<iostream>
using namespace std;
#define maxsize 8
typedef struct {
	int data[maxsize];
	int front;
	int rear;
}Queue;
void init(Queue &q)
{
	q.front = q.rear = 0;
}
int isEmpty(Queue q)
{
	if (q.front == q.rear)
		return 1;
	else
		return 0;
}
int EnQueue(Queue &q,int x)
{
	if ((q.rear + 1) % maxsize == q.front)
		return 0;
	q.rear = (q.rear + 1) % maxsize;
	q.data[q.rear] = x;
	return 1;


}
int DeQueue(Queue &q)
{
	if (q.rear == q.front)return 0;
	q.front = (q.front + 1) % maxsize;
	int x = q.data[q.front];
	return x;
}