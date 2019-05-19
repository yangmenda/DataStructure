#include<iostream>
#include<stdlib.h>
using namespace std;
#define  maxsize 100
typedef struct {
	int data[maxsize];
	int top;

}Stack;
void init(Stack &s)
{
	s.top = -1;
}
int isEmpty(Stack s)
{
	if (s.top = -1)
	{
		return 1;

	}
	else
		return 0;
}
int push(Stack &s, int x)
{
	if (s.top == maxsize - 1)return 0;
	
	s.data[++s.top] = x;
	return 0;
}
int pop(Stack &s, int x)
{
	if (isEmpty(s))
		return 0;
	x = s.data[s.top--];
	
	return 1;
}
int match(char exp[], int n)
{
	char s[maxsize], int top = -1;
	int i;
	for (i = 0; i < n; ++i)
	{
		if (s[i] == '(')s[++top] = '(';
		if (exp[i] == ')')
		{
			if (top == -1)return 0;
			else --top;
		}
		if (top == -1)return 1;
		else return 0;

	}
}