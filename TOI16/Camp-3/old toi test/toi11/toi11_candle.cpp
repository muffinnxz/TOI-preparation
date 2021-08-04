#include<bits/stdc++.h>
using namespace std;

int n, m, ans = 0;
int dir[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
char arr[2000][2000];

int solve(int x, int y)
{
	arr[x][y] = '0';
	
	for(int i=0;i<8;i++)
	{
		int xx = x+dir[i][0], yy = y+dir[i][1];
		if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
		if(arr[xx][yy] != '0') solve(xx, yy);
	}
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;

	for(int i=0;i<n;i++)
		cin >> arr[i];
			
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(arr[i][j] == '1') 
			{
				solve(i, j);
				ans++;
			}
			
	cout << ans;
}
