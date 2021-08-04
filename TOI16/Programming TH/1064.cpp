#include<bits/stdc++.h>
using namespace std;

int n,m,p;
int land[100][100];

void fillWater(int x,int y,int w)
{
	if(x < 0 || x >= n || y < 0 || y >= m) return;
	if(land[x][y] == w || land[x][y] != 2) return;
	
	land[x][y] = w;
	
	fillWater(x+1,y,w);
	fillWater(x-1,y,w);
	fillWater(x,y+1,w);
	fillWater(x,y-1,w);
}

pair<int,int> checkLand(int x,int y,int a)
{
	bool isCount[10000];
	for(int i=0;i<10000;i++)
		isCount[i] = false;
	
	int P = 0;
	for(int i=x;i<x+a;i++)
		for(int j=y;j<y+a;j++)
		{
			if(land[i][j] == 0) return make_pair(-1,-1);
			else if(land[i][j] >= 3 && !isCount[land[i][j]])
			{
				isCount[land[i][j]] = true;
				P++;
			}
		}
	return make_pair(a*a,P);
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>m>>n;
	
	char tmpc;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin>>tmpc;
			if(tmpc == 'S') land[i][j] = 1;
			else if(tmpc == 'P') land[i][j] = 2;
			else land[i][j] = 0;
		}
	p = 3;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(land[i][j] == 2)
			{
				fillWater(i,j,p);
				p++;
			} 
			
	pair<int,int> ans = {-1,999999};
	pair<int,int> tmp;

	for(int a=64;a>=0;a--)
	{
		if(n < a || m < a) continue;
		
		for(int i=0;i<n-a+1;i++)
			for(int j=0;j<m-a+1;j++)
			{
				tmp = checkLand(i,j,a);
				if(tmp.first != -1 && tmp.second < ans.second)
				{
					
					ans.first = tmp.first;
					ans.second = tmp.second;
				}
			}
		if(ans.first != -1) break;
	}
	cout<<ans.first<<" "<<ans.second;
}
