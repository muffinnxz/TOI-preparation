#include<bits/stdc++.h>
using namespace std;

int n,m,t;
int road[105][45];
int visited[105][45];

void drive(string s,int lane,int T)
{
	if(T == t-1) 
	{
		cout<<s;
		return;
	}
	
	visited[T][lane] = true;
	
	if(lane - 1 >= 0 ) if(road[T+1][lane-1] == 0 && !visited[T+1][lane-1]) drive(s+"1\n",lane-1,T+1);
	if(lane + 1 < n) if(road[T+1][lane+1] == 0 && !visited[T+1][lane+1]) drive(s+"2\n",lane+1,T+1);
	if(road[T+1][lane] == 0 && !visited[T+1][lane]) drive(s+"3\n",lane,T+1);
	
	return;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m>>t;
	
	m--;

	for(int i=0;i<t;i++)
		for(int j=0;j<n;j++)
			cin>>road[i][j];
	
	memset(visited,false,sizeof(visited));
				
	drive("",m,-1);
}
