#include<bits/stdc++.h>
using namespace std;

int f(int n,int m,int b[],int *dp)
{
	if(n == 0) return 0;
	if(*(dp+n) != 0) return *(dp+n);
	
	*(dp+n) = INT_MAX;
	for(int i=0;i<m;i++)
		if(n - b[i] >= 0) *(dp+n) = min(*(dp+n),f(n-b[i],m,b,dp) + 1); 
	
	return *(dp+n);
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,m;
	cin>>n>>m;
	
	int b[m],dp[n+1] = {0};	
	
	for(int i=0;i<m;i++)
	{
		cin>>b[i];
		dp[b[i]] = 1;
	}
		
	cout<<f(n,m,b,&dp[0]);
}
