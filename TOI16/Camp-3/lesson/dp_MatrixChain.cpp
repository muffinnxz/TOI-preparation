#include<bits/stdc++.h>
using namespace std;

#define endll "\n"
const int div_prime = 1000000007;

void func()
{
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	int dp[n][n];
	memset(dp,0,sizeof(dp));
			
	for(int d=1;d<n;d++)
	{
		int i=0,j=d;
		while(j < n)
		{
			dp[i][j] = INT_MAX;
			for(int k=i;k<=j;k++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j]);
			i++,j++;
		}
	}
	
	cout<<dp[1][n-1]<<endll;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin>>T;
	
	while(T--) func();
}
