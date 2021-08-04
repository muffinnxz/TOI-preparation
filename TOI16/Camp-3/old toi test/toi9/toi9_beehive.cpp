#include<bits/stdc++.h>
#define endll "\n"
using namespace std;

int n,m,beehive[1001][1001];
pair<int, int> dp[1001][1001]; 
int dir[2][2][2] = {{{1, 0}, {1, -1}}, {{1, 0}, {1, 1}}};

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>beehive[i][j];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m-1;j++)
			dp[i][j].first = 0, dp[i][j].second = 0;
	for(int i=0;i<m;i++)
		dp[n-1][i].first = beehive[n-1][i], dp[n-1][i].second = 1;
	
	for(int i=n-2;i>=0;i--)
		for(int j=0;j<m;j++)
			for(int k=0;k<2;k++)
			{
				int xx = i+dir[i%2][k][0], yy = j+dir[i%2][k][1];
				if(xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
				
				int new_value = beehive[i][j] + dp[xx][yy].first;
				if(new_value > dp[i][j].first) dp[i][j].first = new_value, dp[i][j].second = dp[xx][yy].second;
				else if(new_value == dp[i][j].first) dp[i][j].second += dp[xx][yy].second;
			}
	
	int mx = 0, mx_count = 0;
	for(int i=0;i<m;i++)
		if(dp[0][i].first > mx) mx = dp[0][i].first, mx_count = dp[0][i].second;
		else if(dp[0][i].first == mx) mx_count += dp[0][i].second;
	
	cout<<mx<<" "<<mx_count;
}
