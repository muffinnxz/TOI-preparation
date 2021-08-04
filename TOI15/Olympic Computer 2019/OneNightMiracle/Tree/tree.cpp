#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<list>
#include<stack>
#include<queue>
#include<string.h>
using namespace std;

main()
{
	char x[1000],temp[2];
	char *pch;
	gets(x);
	list<int> tree;
	list<int>::iterator it1,it2;
	pch=strtok(x," ");
	while(pch!=NULL)
	{
		temp[0]=*pch;
		temp[1]='\0';
		tree.push_back(atoi(temp));
		pch=strtok(NULL," ");
	}
	it1=tree.begin();
	it2=it1;
	int c=0;
	for(int i=0;i<tree.size();i++)
	{
		if(*it1<*it2)
		{
			c++;
		}
		else
		{
			c=1;
			it2=it1;
		}
		it1++;
	}
	cout<<c;
}
