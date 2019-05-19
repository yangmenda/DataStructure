#include<iostream>
#include<stdlib.h>
#define maxsize 5
typedef struct ArcNode {
	int adjvex;	//�˱�ָ��Ľڵ�
	struct ArcNode *nextarc;	//ָ����һ���ߵ�ָ��
}ArcNode;	//�߽ڵ�
typedef struct {
	char data;	//�˶�����Ϣ
	ArcNode *first;	//ָ��˶���ĵ�һ���ߵ�ָ��
}Node;	//����ڵ�
typedef struct {
	Node adjlist[maxsize];	//�ṹ�����飬5Ϊ������
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
	p = g->adjlist[v].first;	//�߽ڵ�ָ��ָ�򶥵�v��ָ�ĵ�һ����
	while (p != NULL)
	{
		if (visited[p->adjvex] == 0)	//���˶���δ���ʹ�
			DFS(g, p->adjvex);	//�ݹ���ʴ˽ڵ�
		p = p->nextarc;	//����ָ��ָ����һ����
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