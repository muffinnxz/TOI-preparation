#include<bits/stdc++.h>
using namespace std;

#define endll "\n"
const int div_prime = 1000000007;

void LIS()
{
	int n;
	cin>>n;
	
	int arr[n], dp[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		dp[i] = 1;
	}
	
	int ans = 1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
			if(arr[i] > arr[j]) 
				dp[i] = max(dp[i],dp[j]+1);		
		ans = max(ans,dp[i]);	
	}
		
	cout<<ans<<endll;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin>>T;
	
	while(T--) LIS();
}
