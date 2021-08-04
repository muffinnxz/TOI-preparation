#include<bits/stdc++.h>
using namespace std;

#define endll "\n"
const int div_prime = 1000000007;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin>>n>>k;
	
	int arr[n], dp[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	deque<pair<int,int> > dq;
	dq.push_back(make_pair(arr[0],0));
	
	dp[0] = arr[0];
	for(int i=1;i<n;i++)
	{
		while(!dq.empty() && dq.front().second < i-k) dq.pop_front();
		dp[i] = arr[i] + dq.front().first;
		while(!dq.empty() && dq.back().first > dp[i]) dq.pop_back();
		dq.push_back(make_pair(dp[i],i));
	}
	cout<<dp[n-1];
}
