#include<bits/stdc++.h>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	if(n < 3) cout<<"0";
	else
	{
		sort(arr.begin(),arr.end());
		int A[n-2];	
		for(int i=0;i<n-2;i++)
		{
			auto it = lower_bound(arr.begin(),arr.end(),arr[i] + arr[i+1]);
			if(it != arr.end()) A[i] = distance(arr.begin() + i,it);
			else A[i] = distance(arr.begin() + i,it); 
		}
		int mx = INT_MIN;
		for(int i=0;i<n-2;i++)
			mx = max(mx,A[i]);
		if(mx > 2) cout<<mx;
		else cout<<"0";
	}
	
}
