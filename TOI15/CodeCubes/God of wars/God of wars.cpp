#include<iostream>
#include<queue>
#include<list>
using namespace std;

main()
{
	int n,m;
	cin>>n>>m;
	int s,t;
	cin>>s>>t;
	int i,j;
	int road[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			road[i][j]=0;
	
	int sum=0,max=0;
	
	for(i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		road[u][v]=w;
		road[v][u]=w;
		sum+=w;
	}
	
	priority_queue<int> vertex;
	int weight[n];
	int pred[n];
	for(i=0;i<n;i++)
	{
		pred[i]=s;
		weight[i]=999999;	
	}
	
	vertex.push(s);
	weight[s]=0;
	while(!vertex.empty())
	{
		int temp=vertex.top();
		vertex.pop();
		for(i=0;i<n;i++)
			if(road[temp][i]!=0)
			{
				int nextw=weight[temp]+road[temp][i];
				if(nextw<=weight[i])
				{
					weight[i]=nextw;
					vertex.push(i);
					pred[i]=temp;
				}
			}
	}
		
	list<unsigned long long int> path;
	list<unsigned long long int>::iterator it,temp;
	i=t;
	path.push_back(i);
	do
	{
		int a=t;
		i=pred[i];
		path.push_front(i);
	}while(i!=s);
	
	while(!path.empty())
	{
		int a=path.front();
		path.pop_front();
		if(path.empty()) break;
		int b=path.front();
		if(road[a][b]>=max) max=road[a][b];
	}	
	cout<<sum-weight[t]+max;
}
