#include<bits/stdc++.h>
using namespace std;

#define endll "\n"

void coin_change()
{
	int n,k;
	cin>>n;
	
	int coin[n];
	for(int i=0;i<n;i++)
		cin>>coin[i];
	
	cin>>k;
	
	int dp[n+1][k+1];
	memset(dp,0,sizeof(dp));
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			if(j==0) dp[i][j] = 1;
			else if(i==0) dp[i][j] = 0;
			else
			{
				dp[i][j] = dp[i-1][j];
				if(j - coin[i-1] >= 0) dp[i][j] += dp[i][j-coin[i-1]];
			} 
		}
	}
	cout<<dp[n][k]<<endll;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin>>T;
	
	while(T--) coin_change();
}
