#include<bits/stdc++.h>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	int tree[n];
	for(int i=0;i<n;i++)
		cin>>tree[i];
	
	int dp[n];
	for(int i=0;i<n;i++)
		dp[i] = 1;
	
	int mx = 1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
			if(tree[i] > tree[j] && dp[j] + 1 > dp[i]) dp[i] = dp[j] + 1;
		mx = max(mx,dp[i]);
	}
	
	cout<<mx;
	
}
