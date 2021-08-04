#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> graph[],int u,int v)
{
	graph[u].push_back(v);
	graph[v].push_back(u);
}

void BFS(vector<int> graph[],int n,int m)
{
	queue<pair<int,int> > q;
	q.push(make_pair(0,1));
	
	vector<int> time(n*m,INT_MAX);
	vector<int> parent(n*m,-1);
	
	pair<int,int> node;
	while(!q.empty())
	{
		node = q.front();
		q.pop();
		
		
		if(time[node.first] <= node.second)
		{
			cout<<node.second<<"\n"<<node.first / m + 1<<" "<<node.first % m + 1;
			break;
		}
		
		time[node.first] = node.second;
		
		for(auto v : graph[node.first])
		{
			if( v != parent[node.first])
			{
				parent[v] = node.first;
				q.push(make_pair(v,node.second+1));
			}
		}
	}
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m;

	vector<int> graph[n*m];
	
	char tmp;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>tmp;
			if(tmp == 'R' && j+1 < m) addEdge(graph,i*m+j,i*m+(j+1));
			else if(tmp == 'D' && i+1 < n) addEdge(graph,i*m+j,(i+1)*m+j);
			else if(tmp == 'B')
			{
				if(j+1 < m)addEdge(graph,i*m+j,i*m+(j+1));
				if(i+1 < n)addEdge(graph,i*m+j,(i+1)*m+j);
			}
		}
	}
	
	BFS(graph,n,m);
}
