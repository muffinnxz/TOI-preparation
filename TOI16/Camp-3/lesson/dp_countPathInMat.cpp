#include<bits/stdc++.h>
using namespace std;

#define endll "\n"

const int div_prime = 1000000007;

void count_path()
{
	int n,m;
	cin>>n>>m;
	
	int dp[n][m];
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(i-1 >= 0) dp[i][j] = (dp[i][j] + dp[i-1][j]) % div_prime;
			if(j-1 >= 0) dp[i][j] = (dp[i][j] + dp[i][j-1]) % div_prime;
		}
	
	cout<<dp[n-1][m-1]<<endll;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin>>T;
	
	while(T--) count_path();
}
