#include<iostream>
using namespace std;
#define maxsize 5

typedef struct {
	int no;
}VertexType;
typedef struct {
	int edges[maxsize][maxsize];
	int n, e;
	VertexType vex[maxsize];
}MGraph;
typedef struct {
	int a, b;
	int w;
}Road;
int getRoot(int a, int set[])
{
	while (a != set[a])a = set[a];
	return a;
}
int lowCost(Road road[])
{
	int i;
	int a, b, min;
	int set[100];
	min = 0;
	
}