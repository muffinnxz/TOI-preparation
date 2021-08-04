#include<bits/stdc++.h>
using namespace std;

#define endll '\n'

int dp[150][150];
string s;
int LPstr(int l,int r)
{
	if(l > r) return 0;
	if(dp[l][r] != 0) return dp[l][r];
	
	if(s[l] == s[r]) dp[l][r] = 2 + LPstr(l+1,r-1);
	else dp[l][r] = max( LPstr(l,r-1) , LPstr(l+1,r) );
	
	return dp[l][r];
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>s;
	
	int len = s.length();
	memset(dp,0,sizeof(dp));
	for(int i=0;i<len;i++)
		dp[i][i] = 1;
		
	cout << LPstr(0,len-1);
}
