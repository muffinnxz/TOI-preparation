#include<iostream>
#include<queue>
using namespace std;

main()
{
	int n;
	cin>>n;
	int s,e;
	cin>>s>>e;
	
	int road[n][n]={0};
	int i;
	
	for(i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		road[a-1][b-1]=1; 
	}
	
	priority_queue<int> temp;
	int weight[n]={0};
	temp.push(s);
		
	while(!temp.empty())
	{
		int u=temp.top();
		temp.pop();
		for(i=0;i<n;i++)
			if(road[u][i]!=0)
			{
				int nextw=weight[u]+road[u][i];
				if(nextw>weight[i])
				{
					weight[i]=nextw;
					temp.push(i);
				}
			}
	}
	
	cout<<weight[e-1]+2;
}
