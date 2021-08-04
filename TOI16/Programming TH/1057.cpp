#include<bits/stdc++.h>
#include<queue>
using namespace std;

int n;
vector<vector<int> > file;

bool isAllow(int f)
{
	bool visited[n] = {false};
	queue<int> cmpl;
	cmpl.push(f);
	int u,s;
	while(!cmpl.empty())
	{
		u = cmpl.front();
		s = file[u].size();
		cmpl.pop();
		
		if(visited[u]) return false;
		
		visited[u] = true;
		
		for(int i=0;i<s;i++)
		{
			if(visited[file[u][i]]) return false;
			else cmpl.push(file[u][i]);
		}
	}
	return true;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	
	int m,tmp;
	for(int i=0;i<n;i++)
	{
		cin>>m;
		file.push_back(vector<int> (m));
		for(int j=0;j<m;j++)
		{
			cin>>file[i][j];
			file[i][j]--;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		if(isAllow(i)) cout<<"NO";
		else cout<<"YES";
		cout<<endl;
	}
}
