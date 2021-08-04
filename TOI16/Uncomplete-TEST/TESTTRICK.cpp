#include<bits/stdc++.h>
using namespace std;

#define endll '\n'

int n,k;
int arr[1001];

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>k;
	
	arr[0] = 0;
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		arr[i] += arr[i-1];
	}
	
	int mn = INT_MAX;
	for(int i=1;i<=n-k;i++)
	{
		int mx = 0;
		for(int j=1;j<=n-i+1;j++)
			mx = max(mx,arr[j+i-1] - arr[i-1]);
		mn = min(mn,mx);
	}
	cout<<mn;
}
