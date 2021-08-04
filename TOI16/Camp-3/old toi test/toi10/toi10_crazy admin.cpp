#include<bits/stdc++.h>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	
	int arr[m], l = 0, r = 0;
	for(int i=0;i<m;i++)
	{
		cin >> arr[i];
		l = max(l, arr[i]);
		r += arr[i];
	}
	
	while(l < r)
	{
		int mid = l + (r-l)/2;
		
		int req = 1, sum = 0;
		for(int i=0;i<m;i++)
		{
			sum += arr[i];
			if(sum > mid)
			{
				sum = arr[i];
				req++;	
			}	
		}
		
		if(req <= n) r = mid;
		else l = mid+1;
	}
	
	cout << l;
}
