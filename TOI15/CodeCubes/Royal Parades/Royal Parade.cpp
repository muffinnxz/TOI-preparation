#include<iostream>
#include<queue>
#include<math.h>
#include<list>
using namespace std;

main()
{
	int n,m;
	cin>>n>>m;
	int town[n+1][n+1];
	int i,j;
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
			town[i][j]=0;
	for(i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		town[u][v]=w;
		town[v][u]=w;
	}
			
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	
	int shpath[n+1];
	int weight[n+1];
	int visited[n+1];
	for(i=0;i<=n;i++)
	{
		shpath[i]=0;
		visited[i]=0;
		weight[i]=9999999;
	}
	priority_queue<int> temp;
	weight[a]=0;
	visited[a]=1;
	temp.push(a);
	while(!temp.empty())
	{
		int u=temp.top();
		temp.pop();
		for(i=1;i<=n;i++)
			if(town[u][i]!=0&&!visited[i])
			{
				int nextw=weight[u]+town[u][i];
				if(nextw<weight[i])
				{
					weight[i]=nextw;
					temp.push(i);
					shpath[i]=u;
				}
			}
	}
	
	
	int flag=0;
	int x=b;
	while(!flag)
	{
		for(i=1;i<n;i++)
		{
			town[x][i]=0;
			town[i][x]=0;
		}
		x=shpath[x];
		if(x==0) flag=1;
	}
	
	for(i=0;i<=n;i++)
	{
		visited[i]=0;
		weight[i]=9999999;
	}
		
	weight[c]=0;
	temp.push(c);
	while(!temp.empty())
	{
		int u=temp.top();
		temp.pop();
		for(i=1;i<=n;i++)
		{
			if(town[u][i]!=0&&!visited[i])
			{
				int nextw=weight[u]+town[u][i];
				if(nextw<weight[i])
				{
					weight[i]=nextw;
					temp.push(i);
				}
			}
		}
	}
	
	if(weight[d]==9999999) cout<<-1;
	else cout<<weight[d];
}
