#include<bits/stdc++.h>
using namespace std;

#define endll "\n"
const int div_prime = 1000000007;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m,k;
	cin>>n>>m>>k;
	
	int arr[n+2][m+2], dp[n+2][m+2], dp2[n+2][m+2];
	memset(arr,0,sizeof(arr));
	memset(dp,0,sizeof(dp));
	memset(dp2,0,sizeof(dp2));
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>arr[i][j];
			arr[i][j] = arr[i][j] + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
			dp[i][j] = dp[i-1][j-1] + arr[i][j] - arr[i-1][j];  
		}
		
	for(int i=1;i<=n;i++)
		for(int j=m;j>=1;j--)
			dp2[i][j] = dp2[i-1][j+1] + arr[i][m] - arr[i][j-1] - arr[i-1][m] + arr[i-1][j-1];
	
	int ans = INT_MIN;	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int left = INT_MIN, rigth = INT_MIN;
			if(i >= k && j >= k) ans = max(ans, dp[i][j] - arr[i][j-k] + arr[i-k][j-k] - dp[i-k][j-k]);
			if(i >= k && j+k <= m+1) ans = max(ans, dp2[i][j] - arr[i][m] + arr[i][j+k-1] + arr[i-k][m] - arr[i-k][j+k-1] - dp2[i-k][j+k]);
		}
	cout<<ans;
}
