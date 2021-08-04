#include<stdio.h>
#include<stack>
#include<queue>
#include<iostream>
using namespace std;

main()
{
	queue<int> line;
	int n,m,i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		line.push(i);
	while(!line.empty())
	{
		i=1;
		cout<<i<<" : ";
		for(j=0;j<m;j++)
		{
			cout<<line.front()<<" ";
			line.pop();
			if(line.empty()) break;
		}
		cout<<endl;
	}
}
