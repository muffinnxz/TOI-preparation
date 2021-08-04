#include<bits/stdc++.h>
using namespace std;

int n;
double work[21][21];
double dp[1<<21];

double findmaxP(int d,int s)
{
	if(d == n) return 1.0;

	if(dp[s] != -1) return dp[s];
	
	dp[s] = 0;
	for(int i=0;i<n;i++)
		if((s & (1<<i)) == 0)
			dp[s] = max(dp[s],work[d][i] * findmaxP(d+1,(s|(1<<i))));
	
	return dp[s];
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	
	double tmp;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cin>>tmp;
			work[i][j] = tmp / 100.0;
		}
		
	for(int i=0;i<(1<<n+1);i++)
		dp[i] = -1;
		
	double maxP = findmaxP(0,0);
	printf("%.12lf",maxP*100);
}
