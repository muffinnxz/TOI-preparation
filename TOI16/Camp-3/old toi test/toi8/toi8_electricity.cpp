#include<bits/stdc++.h>
using namespace std;

#define endll "\n"
const int div_prime = 1000000007;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,k;
	cin>>n>>k;
	
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	int dp[n];
	memset(dp,0,sizeof(dp));
	dp[0] = arr[0];
	
	multiset<int> minheap;
	minheap.insert(arr[0]);
	
	for(int i=1;i<n;i++)
	{
		if(i-k-1 >= 0) minheap.erase(minheap.find(dp[i-k-1]));
		dp[i] = *minheap.begin() + arr[i];
		minheap.insert(dp[i]);
	}
	cout<<dp[n-1];
}
