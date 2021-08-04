#include<stdio.h>
#include<stack>
#include<list>
#include<queue>
#include<iostream>
using namespace std;

main()
{
	int n,m;
	cin>>n;
	cin>>m;
	int i,j,totalprice=0;
	priority_queue<int> price,*p,pick;
	for(i=0;i<n;i++)
	{
		cin>>j;
		price.push(j);
	}
	for(i=0;i<m;i++)
	{
		totalprice+=price.top();
		pick.push(price.top());
		price.pop();
	}
	cout<<totalprice;
	
	
}
