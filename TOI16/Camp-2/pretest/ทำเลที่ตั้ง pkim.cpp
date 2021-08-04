#include<bits/stdc++.h>
using namespace std;

main()
{
	int n,m,k;
	cin>>n>>m>>k;
	
	int dp[n+1][m+1];
	memset(dp,0,sizeof(dp));
	
	int tmp;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>tmp;
			dp[i][j] = tmp + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
		}
	
	int ans = INT_MIN;
	for(int i=k-1;i<=n;i++)
		for(int j=k-1;j<=m;j++)
			ans = max(ans, dp[i][j] - dp[i-k+1][j] - dp[i][j-k+1] + dp[i-k+1][j-k+1]);
	cout<<ans;
}
