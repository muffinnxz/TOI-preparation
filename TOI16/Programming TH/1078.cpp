#include<bits/stdc++.h>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n;
	cin>>n;
	
	long long arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	sort(arr,arr+n);
	
	long long i = 0, j = n-1;
	long long ans = 0;
	while(i < j) ans += arr[j--] - arr[i++];
	
	cout<<ans;
}
