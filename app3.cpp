#include<iostream>
using namespace std;
#define maxsize 10
typedef struct ArcNode {
	int adjvex;
	struct ArcNode *next;
}ArcNode;
typedef struct {
	char data;
	int count;
	ArcNode *first;
}Node;
typedef struct {
	Node adjlist[maxsize];
	int n, e;
}Graph;
int TopSort(Graph *g)
{
	int i, j, n = 0;
	int stack[maxsize], top = -1;
	ArcNode *p;
	for (i = 0; i < g->n; ++i)
		if (g->adjlist[i].count == 0)
			stack[++top] = i;
	while (top != -1)
	{
		i = stack[top--];
		++n;
		cout << i << " ";
		p = g->adjlist[i].first;
		while (p != NULL)
		{
			j = p->adjvex;
			--(g->adjlist[j].count);
			if (g->adjlist[j].count == 0)
			{
				stack[++top] = j;
			}
			p = p->next;
		}
	}
	if (n == g->n)return 1;
	else return 0;
}
int BFS(Graph *g, int vi, int vj)
{
	ArcNode *p;
	int que[maxsize], rear = 0, front = 0;
	int visit[maxsize];
	int i, j;
	for (i = 0; i < g->n; ++i)visit[i] = 0;
	rear = (rear + 1) % maxsize;
	que[rear] = vi;
	visit[vi] = 1;
	while (front != rear)
	{
		front = (front + 1) % maxsize;
		j = que[front];
		if (j == vj)return 1;
		p = g->adjlist[j].first;
		while (p != NULL)
		{
			if (visit[p->adjvex] == 0)
			{
				rear = (rear + 1) % maxsize;
				que[rear] = p->adjvex;
				visit[p->adjvex] = 1;
			}
			p = p->next;
		}
	}
	return 0;
}
int visit[maxsize], sum;
void DFS(Graph *g, int v)
{
	ArcNode  *p;
	visit[v] = 1;
	++sum;
	p = g->adjlist[v].first;
	while (p != NULL) {
		if (visit[p->adjvex] == 0)
		{
			DFS(g, p->adjvex);
			p = p->next;
			p = p->next;
		}
	}
}
void print(Graph *g)
{
	int i, j;
	for (i = 0; i < g->n; ++i)
	{
		sum = 0;
		for (j = 0; j < g->n; ++j)
		{
			visit[j] = 0;
		}
		DFS(g, i);
		if (sum == g->n)
			cout << i << endl;
	}
}
int count(Graph *g, int k)
{
	ArcNode *p;
	int i, sum;
	sum = 0;
	for (i = 0; i < g->n; ++i)
	{
		p = g->adjlist[i].first;	//p为与i连得一条边
		while (p)
		{
			if (p->adjvex == k)		//如果与此边相连的顶点为k，则计数器加一
			{
				++sum;
				break;
			}
			p = p->next;
		}
	}
	return sum;
}
