#include<bits/stdc++.h>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,k;
	cin>>n>>k;
	
	double arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	double sum = 0;
	for(int i=0;i<k-1;i++)
		sum += arr[i];
	
	double ans[n-k+1];
	for(int i=k-1;i<n;i++)
	{
		sum += arr[i];
		ans[i-k+1] = sum / k;
		sum -= arr[i-k+1]; 	
	}
	
	cout<<fixed<<setprecision(6);
	cout<<n-k+1<<"\n";
	for(int i=1;i<=n-k+1;i++)
	{
		cout<<ans[i-1];
		if(i % 3 == 0) cout<<"\n";
		else cout<<" ";
	}
}
