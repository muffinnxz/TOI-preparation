#include<bits/stdc++.h>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,k;	
	cin>>n>>k;
		
	int dp[n+1];
	dp[0] = 1;
	dp[1] = 1;
	
	if(k > n) k = n;
	
	int sum = 1;
	for(int i=2;i<=k;i++)
	{
		dp[i] = (dp[i-1] * 2) % 2009;
		sum = (sum + dp[i]) % 2009; 
	}
		
	
	if(k == n) cout<<dp[n];
	else
	{
		dp[k+1] = sum;
		for(int i = k+2 ;i <= n ;i++)
		{
			sum = (sum - dp[i-k-1] + 2009) % 2009;
			sum = (sum + dp[i-1]) % 2009;
			dp[i] = sum;
		}
		cout<<dp[n];
	}
}
