#include<iostream>
#include<stdlib.h>
#define maxsize 5
typedef struct ArcNode {
	int adjvex;	//此边指向的节点
	struct ArcNode *nextarc;	//指向下一条边的指针
}ArcNode;	//边节点
typedef struct {
	char data;	//此顶点信息
	ArcNode *first;	//指向此顶点的第一条边的指针
}Node;	//顶点节点
typedef struct {
	Node adjlist[maxsize];	//结构体数组，5为顶点数
	int n, e;
}Graph;	
void visit(int v)
{

}
int visited[maxsize];
void DFS(Graph *g, int v)
{
	ArcNode *p;
	visited[v] = 1;
	visit(v);
	p = g->adjlist[v].first;	//边节点指针指向顶点v所指的第一条边
	while (p != NULL)
	{
		if (visited[p->adjvex] == 0)	//若此顶点未访问过
			DFS(g, p->adjvex);	//递归访问此节点
		p = p->nextarc;	//将此指针指向下一条边
	}
}
void BFS(Graph *g, int v, int visited[maxsize])
{
	ArcNode *p;
	int queue[maxsize], front = 0, rear = 0;
	int j;
	visit(v);
	visited[v] = 1;
	rear = (rear + 1) % maxsize;
	queue[rear] = v;
	while (front != rear)
	{
		
		front = (front + 1) % maxsize;
		j = queue[front];
		p = g->adjlist[j].first;
		while (p != NULL)
		{
			if (visited[p->adjvex]==0)
			{
				visit(p->adjvex);
				visited[p->adjvex] = 1;
				rear = (rear + 1) % maxsize;
				queue[rear] = p->adjvex;
			}
			p = p->nextarc;
		}
	}
}