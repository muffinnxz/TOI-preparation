#include<bits/stdc++.h>
using namespace std;

#define endll '\n'

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	char land[n][m];
	for(int i=0;i<n;i++)
		cin>>land[i];
	
	int sqr[n][m];
	
	int x = min(n,m);
	int ans[x+1];
	for(int i=0;i<x+1;i++)
		ans[i] = 0;
		
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i == 0 || j == 0) sqr[i][j] = (int)(land[i][j] - '0');
			else if(land[i][j] == '0') sqr[i][j] = 0;
			else sqr[i][j] = min(sqr[i-1][j-1],min(sqr[i-1][j],sqr[i][j-1])) + 1;
			if(sqr[i][j] <= x)ans[sqr[i][j]]++;
		}
	}
	
	for(int i=x-1;i>=0;i--)
		ans[i] += ans[i+1];
	
	for(int i=1;i<x+1;i++)
		cout<<ans[i]<<endll;
}
