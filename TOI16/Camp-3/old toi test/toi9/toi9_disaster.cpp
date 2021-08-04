#include<bits/stdc++.h>
#define endll "\n"
using namespace std;

vector<int> graph[26];
bool visited[26][26];
int n;

bool solve(int u, int cnt)
{
	if(cnt == n)
	{
		cout<<char('A' + u)<<" ";
		return true;
	} 
	
	for(auto v : graph[u])
		if(!visited[u][v])
		{
			visited[u][v] = true;
			visited[v][u] = true;
			if(solve(v, cnt+1))
			{
				cout<<char('A' + u)<<" "; 
				return true;
			}
			visited[u][v] = false;
			visited[v][u] = false;
		}
	return false;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		int u = int(s[0] - 'A'), v = int(s[1] - 'A');
		graph[u].push_back(v);
		graph[v].push_back(u);	
	}
	
	for(int i=0;i<26;i++)
		if(solve(i,0)) exit(0);
}
