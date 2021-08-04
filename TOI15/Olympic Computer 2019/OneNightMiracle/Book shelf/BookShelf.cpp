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
	
	list<int> book;
	list<int>::iterator it1;
	
	pch=strtok(x,",");
	while(pch!=NULL)
	{
		temp[0]=*pch;
		temp[1]='\0';
		book.push_back(atoi(temp));
		pch=strtok(NULL,",");
	}
	for(it1=book.begin();it1!=book.end();it1++)
		cout<<*it1<<" ";
	cout<<endl;
	int i,ncmd;
	cin>>ncmd;
	char cmd;
	for(i=0;i<ncmd;i++)
	{
		cin>>cmd;
		if(cmd=='D') book.erase(book.begin());
		else if(cmd=='E')
		{
			int e;
			cin>>e;
			book.push_back(e);
		}
	}
	book.sort();
	int a=book.size();
	book.unique();
	int b=book.size();
	if(a==b) cout<<"No the same book!";
	else cout<<"Have the same book!";
}
