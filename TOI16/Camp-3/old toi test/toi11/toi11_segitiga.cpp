#include<bits/stdc++.h>
using namespace std;

#define endll "\n"
const int div_prime = 1000000007;

int sp_operate[3][3] = {{2,1,0},{2,1,1},{1,2,1}};

int func()
{
	int n;
	cin>>n;
	
	string s;
	cin>>s;

	int arr[n];
	bool dp[n][n][3];
	for(int i=0;i<n;i++)
		arr[i] = s[i] - '0';
	
	memset(dp,false,sizeof(dp));
	
	for(int i=0;i<n;i++) 
		dp[i][i][arr[i]] = true;
	
	for(int d=1;d<n;d++)
	{
		int i=0,j=d;
		while(j < n)
		{
			for(int k=i;k<=j;k++)
			{
				for(int a=0;a<3;a++)
					for(int b=0;b<3;b++)
						if(dp[i][k][a] && dp[k+1][j][b]) dp[i][j][sp_operate[a][b]] = true;
				if(dp[i][j][0] && dp[i][j][1] && dp[i][j][2]) break;
			}
			i++,j++;
		}
	}
	
	if(dp[0][n-1][0]) cout<<"yes"<<endll;
	else cout<<"no"<<endll;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T = 20;
	while(T--) func();
}
