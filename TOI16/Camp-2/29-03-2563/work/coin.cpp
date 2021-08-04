#include<bits/stdc++.h>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	int c[n+1] = {0},f[n+1] = {0};
	for(int i=1;i<=n;i++)
		cin>>c[i];
	
	if(n == 1) cout<<c[1];
	else
	{
		f[0] = 0;
		f[1] = c[1];
		for(int i=2;i<=n;i++)
			f[i] = max(f[i-2] + c[i],f[i-1]);
		cout<<f[n];
	}
}
