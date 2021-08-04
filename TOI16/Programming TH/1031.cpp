#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;

main()
{
	int k,n,m;
	cin>>k>>n>>m;
	
	int a,b;
	vector<vector<int> > ladder(n+1);
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		ladder[a].push_back(b);
	}
	
	vector<int> powLos(n+1,INT_MAX);
	vector<bool> visited(n+1,false);
	priority_queue<int> way_queue;
	way_queue.push(1);
	powLos[1]=0;
	visited[1] = true;
	
	while(!way_queue.empty())
	{
		int u=way_queue.top();
		way_queue.pop();
		int noLadder=ladder[u].size();
		
		for(int i=0;i<noLadder;i++)
		{
			int v=ladder[u][i];
			if(powLos[u]+1<powLos[v])
			{
				powLos[v]=powLos[u]+1;
				visited[v]=true;
				way_queue.push(v);
			}
		}
	}
	
	for(int i=n+1;i>0;i--)
	{
		if(visited[i]&&powLos[i]<=k)
		{
			cout<<i;
			break;
		}
	}
}
