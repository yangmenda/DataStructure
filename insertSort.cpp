#include <iostream>
using namespace std;
typedef struct Node
{
	char data;
	struct Node *next;
}Node;
void insertSort(int r[], int n)
{
	int i, j;
	int temp;
	for (i = 1; i < n; ++i)
	{
		temp = r[i];
		j = i - 1;	//jָ��ǰ�����һ��λ��
		while (j >= 0 && temp < r[j])
		{
			r[j + 1] = r[j];	//��j�����λ
			--j;	//�Ӵ˵���ǰ�����������Ƿ��б������Ԫ��
		}
	}
	r[j + 1] = temp;
}
void createLink(Node *&h, char r[], int n)
{
	int i;
	Node *s, *t;
	h = (Node*)malloc(sizeof(Node));
	h->next = NULL;
	t = h;
	for (i = 0; i < n; ++i)
	{
		s = (Node*)malloc(sizeof(Node));
		s->data = r[i];
		t->next = s;
		t = s;
	}
	t->next = NULL;
}