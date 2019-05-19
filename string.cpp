#include<iostream>
#include<stdlib.h>
using namespace std;
#define maxsize 50
typedef struct
{
	char *ch;
	int length;
}str;
typedef struct {
	char ch[maxsize];
	int length;
}str2;
int strassign(str &s, char* ch)
{
	if (s.ch)
	{
		
		free(s.ch);
	}
	int len = 0;
	char *c = ch;
	while (*c)
	{
		++len;
		++c;
	}
	if (len == 0)
	{
		s.ch = NULL;
		s.length = 0;
		return 1;
	}
	else
	{
		s.ch = (char*)malloc(sizeof(char)*(len + 1));
		if (s.ch == NULL)
			return 0;
		else {
			c = ch;
			for (int i = 0; i <= len; ++i, ++c)
			{
				s.ch[i] = *c;
			}
			s.length = len;
			return 1;
		}
	}
}
int strLength(str s)
{
	return s.length;
}
int compare(str s1, str s2)
{
	for (int i = 0; i < s1.length && i < s2.length; ++i)
	{
		if (s1.ch[i] != s2.ch[i])
			return s1.ch[i] - s2.ch[i];
	}
	return s1.length - s2.length;
}
int concat(str &s, str str1, str str2)
{
	if (s.ch)
	{
		free(s.ch);
		s.ch = NULL;
	}
	s.ch = (char*)malloc(sizeof(char)*(str1.length + str2.length + 1));
	if (s.ch == NULL)
	{
		return 0;
	}
	int i = 0;
	while (i < str1.length)
	{
		s.ch[i] = str1.ch[i];	//将str1中数据拷贝到s中
		++i;
	}
	int j = 0;
	while (j <= str2.length)
	{
		s.ch[i + j] = str2.ch[j];	//将str2中数据拷贝到s中s第一组数据之后
		++j;
	}
	s.length = str1.length + str2.length;
	return 1;
}
int substring(str &subs, str s, int pos, int len)
{
	if (pos < 0 || pos >= s.length || len<0 || len>s.length - pos)
		return 0;
	if (subs.ch)
	{
		free(subs.ch);
		subs.ch = NULL;
	}
	if (len == 0)
	{
		subs.ch = NULL;
		subs.length = 0;
		return 1;
	}
	else {
		subs.ch = (char*)malloc(sizeof(char)*len + 1);
		int i = pos;
		int j = 0;
		while (i < pos + len)
		{
			subs.ch[j] = s.ch[i];
			++i;
			++j;
		}
		subs.ch[j] = '\0';
		subs.length = len;
		return 1;
	}
	
}
int clearS(str &s)
{
	if (s.ch)
	{
		free(s.ch);
		s.ch = NULL;
	}
	s.length = 0;
	return 1;

}
int index(str str1, str str2)
{
	int i = 1, j = 1,k = i;
	while (i<=str1.length&&j<=str2.length)
	{
		if (str1.ch[i] == str2.ch[j])
		{
			++i;
			++j;

		}
		else {
			j = 1;
			i=++k;

		}
		if (j > str2.length)return k;
		else return 0;
	}
}
void dell(str2 &s, char ch)
{
	if (s.length != 0)
	{
		for(int i=0;i<s.length;)
			if (s.ch[i] == ch)
			{
				for (int j = i; j < s.length - 1; ++j)
				{
					s.ch[j]=s.ch[j + 1];
				}
				--s.length;
			}
			else {
				++i;

			}
		s.ch[s.length] = '\0';
	}
}
void del(str2 &s, char ch)
{
	if (s.length != 0)
	{
		int ch_num = 0;
		int i, j;
		i = 0;
		while (s.ch[i] != '\0')
		{
			if (s.ch[i] == ch)
			{
				++ch_num;
				for (j = i; s.ch[j] != ch && s.ch[j] != '\0'; ++j)
				{
					s.ch[j - ch_num] = s.ch[j];
				}
				i = j;
				--s.length;
			}
			else {
				++i;
			}
		}
		s.ch[s.length] = '\0'; 
	}
}
void dd(str2 &s, int i, int j)
{
	if (i < s.length&&i >= 0 && j >= 0)
	{
		for (int k = i + j; k < s, length; ++k)
		{
			s.ch[k - j] = s.ch[k];
			s.length -= (s.length - i < j ? s.length - i : j);
			s.ch[s.length] = '\0'; 
	}
}