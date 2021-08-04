#include<bits/stdc++.h>
#include<vector>
#include<string>
using namespace std;

void printlcs(int x,int y,char sub[],int m,int *dp)
{
	if(x==0 || y==0) return;
	if(*(dp+x*m+(y-1)) == *(dp+(x-1)*m+y)) 
	{
		printlcs(x-1,y-1,sub,m,dp);
		cout<<sub[y-1];
	}
	else if(*(dp+x*m+(y-1)) > *(dp+(x-1)*m+y)) printlcs(x,y-1,sub,m,dp);
	else printlcs(x-1,y,sub,m,dp);
}

main()
{
	char s[1000];
	char sub[100];
	
	cin>>s>>sub;
	
	int n = strlen(s);
	int m = strlen(sub);
	
	int dp[n+1][m+1] = {0};
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			dp[i][j] = 0;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
			if(s[i-1] == sub[j-1]) dp[i][j]++;
		}
		
	cout<<dp[n][m]<<endl;
	printlcs(n,m,sub,m+1,&dp[0][0]);
}
