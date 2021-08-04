#include<bits/stdc++.h>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m,k;
	cin>>m>>n>>k;
	
	int direct[5][2] = {{0,0},{-1,0},{0,1},{1,0},{0,-1}};
	int field[n][m];
	bool visited[n][m];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>field[i][j];
	int x,y,tmp;
	while(k--)
	{
		cin>>y>>x;
		x--; y--;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				visited[i][j] = false;
		while(x >= 0 && x < n && y >= 0 && y < m)
		{
			if(visited[x][y]) 
			{
				cout<<"NO";
				break;
			}
			
			visited[x][y] = true;
			
			tmp = x;
			x += direct[field[tmp][y]][0];
			y += direct[field[tmp][y]][1];
		}
		if(x < 0) cout<<"N";
		else if(x >= n) cout<<"S";
		else if(y < 0) cout<<"W";
		else if(y >= m) cout<<"E";
		cout<<endl;
	}
}
