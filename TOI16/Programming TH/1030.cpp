#include<bits/stdc++.h>
using namespace std;

#define endll '\n'

main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	long long arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	long long f = 1;
	for(int i=1;i<=n-2;i++)
		f = (f * i) % 49999;
	
	sort(arr,arr+n);
	
	long long sum = 0;
	long long x;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			x = arr[j] - arr[i];
			if(x >= 0) x %= 49999;
			else while(x < 0) x += 49999;
			
			x = (x * f) % 49999;
			sum = ( sum + x ) % 49999;
		}
	cout<<sum;
}