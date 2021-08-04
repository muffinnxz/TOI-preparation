#include<stdio.h>
#include<stack>
#include<iostream>
using namespace std;

main()
{
	int n,m;
	cin>>n;
	stack<int> train[n],temp;
	int i,j;
	cin>>m;
	
	for(i=0;i<n;i++)
		for(j=0;j<=m;j++)
			train[i].push(j);
	
	for(i=0;i<n;i++)
	{
		int a;
		char b;
		int c;
		cin>>a>>b;
		if(b=='A')
		{
			while(train[i].top()!=a-1)
			{
				cout<<train[i].top()<<" ";
				temp.push(train[i].top());
				train[i].pop();
			}
			while(!temp.empty())
			{
				cout<<temp.top()<<" ";
				temp.pop();
			}
			cout<<endl;
		}
		if(b=='I')
		{
			while(train[i].top()!=a)
			{
				cout<<train[i].top()<<" ";
				temp.push(train[i].top());
				train[i].pop();
			}
			cout<<n+1;
			while(!temp.empty())
			{
				cout<<temp.top()<<" ";
				temp.pop();
			}
			cout<<endl;
		}
		if(b=='D')
		{
			while(train[i].top()!=a)
			{
				cout<<train[i].top()<<" ";
				temp.push(train[i].top());
				train[i].pop();
			}
			cout<<train[i].top()<<" ";
			train[i].pop();
			while(!temp.empty())
			{
				cout<<temp.top()<<" ";
				temp.pop();
			}
			cout<<endl;
		}
	}
}
