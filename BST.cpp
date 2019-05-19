#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct Node {
	int key;
	struct Node *lchild;
	struct Node *rchild;
}Node;
Node* BSTsearch(Node *bt, int key)
{
	if (bt == NULL)return NULL;
	else {
		if (bt->key == key)return bt;
		else if (bt->key < key)return BSTsearch(bt->rchild, key);
		else if (bt->key > key)return BSTsearch(bt->lchild, key);
	}
}
int BSTinsert(Node *&bt, int key)
{
	if (bt == NULL)
	{
		bt = (Node*)malloc(sizeof(Node));
		bt->lchild = bt->rchild = NULL;
		bt->key = key;
		return 1;
	}
	else {
		if (key == bt->key)
			return 0;
		else if (key > bt->key)BSTinsert(bt->rchild, key);
		else if (key < bt->key)BSTinsert(bt->lchild, key);
	}
}
void createBST(Node *&bt, int key[], int n)
{
	int i;
	bt = NULL;
	for (i = 0; i < n; ++i)
		BSTinsert(bt, key[i]);
		BSTinsert(bt, key[i]);
}