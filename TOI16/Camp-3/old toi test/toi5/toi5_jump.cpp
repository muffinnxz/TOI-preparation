#include<bits/stdc++.h>
#define endll "\n"
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, k;
	cin>>n>>k;
	
	int line[n+1];
	for(int i=0;i<n;i++)
		cin>>line[i];
	
	int u = 0, v = 0, mx = 0;
	line[n] = INT_MAX;
	while(u < n && v < n)
	{
		if(line[u] + k >= line[v+1]) 
		{
			v++;
			mx = max(mx, v - u);
		}
		else u++;
	}
	cout<<mx;
}
