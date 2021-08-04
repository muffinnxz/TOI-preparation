#include<bits/stdc++.h>
using namespace std;

#define endll '\n'

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	long long x[n] , y[n];
	for(int i=0;i<n;i++)
		cin>>x[i]>>y[i];
	
	sort(x,x+n);
	sort(y,y+n);
	
	long long ans = 0;
	for(int i=0;i<n;i++)
		ans += (x[i]+y[i]) * (2*i-n+1);
	cout<<ans;
}
