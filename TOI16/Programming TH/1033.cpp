#include<bits/stdc++.h>
using namespace std;

bool CanMove(int x,int y,int n,int now[][2],int p)
{
	if(x<0||x>=n||y<0||y>=n) return false;
	for(int i=0;i<4;i++)
	{
		if(i == p) continue;
		if(x == now[i][0] && y == now[i][1]) return false;
	}
	return true;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,k;
	cin>>n>>k;
	
	int map[n][n];
	int now[4][2];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			map[i][j] = 4;
			
	char walk[4][k];
	
	for(int i=0;i<4;i++)
		for(int j=0;j<k;j++)
			cin>>walk[i][j];		
			
			
	map[0][n-1] = 0;
	map[n-1][n-1] = 1;
	map[n-1][0] = 2;
	map[0][0] = 3;
	
	now[0][0] = 0; now[0][1] = n-1;
	now[1][0] = n-1; now[1][1] = n-1;
	now[2][0] = n-1; now[2][1] = 0;
	now[3][0] = 0; now[3][1] = 0;
	
	char tmp;
	
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(walk[j][i] == 'N')
			{
				if(CanMove(now[j][0] - 1,now[j][1],n,now,j)) 
				{
					now[j][0]--;
					map[now[j][0]][now[j][1]] = j;
				}
			}
			else if(walk[j][i] == 'S')
			{
				if(CanMove(now[j][0] + 1,now[j][1],n,now,j)) 
				{
					now[j][0]++;
					map[now[j][0]][now[j][1]] = j;
				}
			}
			else if(walk[j][i] == 'E')
			{
				if(CanMove(now[j][0],now[j][1] + 1,n,now,j)) 
				{
					now[j][1]++;
					map[now[j][0]][now[j][1]] = j;
				}
			}
			else
			{
				if(CanMove(now[j][0],now[j][1] - 1,n,now,j)) 
				{
					now[j][1]--;
					map[now[j][0]][now[j][1]] = j;
				}
			}
		}
	}
	
	int area[5] = {0};
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			area[map[i][j]]++;
			
	if(area[4] > 0) cout<<"No"<<endl;
	else
	{
		int max = 0,win = 0;
		for(int i=0;i<4;i++)
			if(area[i] > max) max = area[i];
		for(int i=0;i<4;i++)
			if(area[i] == max) win++;
		cout<<win<<" "<<max<<endl;
		for(int i=0;i<4;i++)
			if(area[i] == max) cout<<i+1<<endl;
	}
}
