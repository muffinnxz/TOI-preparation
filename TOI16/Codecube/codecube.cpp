#include<bits/stdc++.h>
using namespace std;

int n,q;
int door[200001];
int group[200001];
int order[200001];

#define endll "\n"

void bfs(int u,int x,int cnt)
{
	group[u] = x , order[u] = cnt;
	if(group[door[u]] == 0) bfs(door[u],x,cnt+1);
}

void group_up()
{
	for(int i=1;i<=n;i++)
		if(group[i] == 0) bfs(i,i,1);
}

bool is_group(int a,int b)
{
	return group[a] == group[b];
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>q;
	
	for(int i=1;i<=n;i++)
		cin>>door[i];
		
	memset(group,0,sizeof(group));
	
	group_up();
	
	int s,e,a,b;
	while(q--)
	{
		cin>>s>>e>>a>>b;
		if(!is_group(s,e))
		{
			if((is_group(s,a) && is_group(e,b)) || (is_group(s,b) && is_group(e,a))) cout<<"DEAD";
			else cout<<"SURVIVE";
		}
		else
		{
			if(!is_group(s,a) || !is_group(s,b)) cout<<"DEAD";
			else
			{
				if(order[s] > order[e])
				{
					int tmp = s;
					s = e;
					e = tmp;
				}
				if((order[s] <= order[a] && order[a] < order[e]) == (order[s] <= order[b] && order[b] < order[e])) cout<<"DEAD";
				else cout<<"SURVIVE";
			}
		}
		cout<<endll;
	}
}
