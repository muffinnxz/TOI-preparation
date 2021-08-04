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
	
	priority_queue<pair<int,int> , vector<pair<int,int> > , greater<pair<int,int> > > minheap;
	minheap.push(make_pair(arr[0],0));
	
	dp[0] = arr[0];
	for(int i=1;i<n;i++)
	{
		while(minheap.top().second < i-k) minheap.pop();
		dp[i] = arr[i] + minheap.top().first;
		minheap.push(make_pair(dp[i],i));
	}
	cout<<dp[n-1];
}
