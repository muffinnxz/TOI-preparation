#include<bits/stdc++.h>
using namespace std;

#define endll "\n"
const int div_prime = 1000000007;

int n,m,dp[105][105];
bool visited[105][105];
string a,b;

int LCS(int i,int j)
{
	if(i==0 || j==0) return 0;
	if(visited[i][j]) return dp[i][j];
	
	visited[i][j] = true;
	
	if(a[i-1] == b[j-1]) dp[i][j] = 1 + LCS(i-1,j-1);
	else dp[i][j] = max(LCS(i-1,j),LCS(i,j-1));
	
	return dp[i][j]; 
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin>>T;
	
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		memset(visited,false,sizeof(visited)); 
		cin>>n>>m>>a>>b;
		cout<<LCS(n,m)<<endll;
	}
		
}
