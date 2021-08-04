#include<bits/stdc++.h>
#include<vector>
using namespace std;
#define N 5
#define M 6
int c[N][M] = 	{{0,0,0,0,1,0}
			    ,{0,1,0,1,0,0}
			    ,{0,0,0,1,0,1}
			    ,{0,0,1,0,0,1}
			    ,{1,0,0,0,1,0}};
int dp[N][M];
int f(int x,int y)
{
	if(x < 0 || x >= N || y < 0 || y >= M) return 0;
	if(dp[x][y] != 0) return dp[x][y];
	
	dp[x][y] = max(f(x-1,y),f(x,y-1)) + c[x][y];
	
	return dp[x][y];
}

// most up left point of c is [0][0] 
main()
{
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			dp[i][j] = 0;
	cout<<f(N-1,M-1)<<endl;
}
