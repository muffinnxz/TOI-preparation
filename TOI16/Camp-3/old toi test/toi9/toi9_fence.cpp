#include<bits/stdc++.h>
using namespace std;

#define endll "\n"
const int div_prime = 1000000007;

int n,m,k,arr[501][501];

int cal_sq(int x,int y,int s)
{
	return arr[x][y] - arr[x-s][y] - arr[x][y-s] + arr[x-s][y-s];
}

bool is_allow_sq(int x, int y, int s)
{
	if(s <= 2) return cal_sq(x,y,s) == 0;
	
	int big_sq = cal_sq(x,y,s);
	int small_sq = cal_sq(x-1,y-1,s-2);
	return big_sq == small_sq;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 2;
	
	while(t--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		
		memset(arr,0,sizeof(arr));
		
		int a,b;
		for(int i=0;i<k;i++)
		{
			cin>>a>>b;
			arr[a+1][b+1] = 1;
		}
		
		int ans = 0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1]; 
				int s = min(i,j);
				while(s && s > ans) 
				{
					if(is_allow_sq(i,j,s)) 
					{
						ans = max(ans, s);
						break;
					}
					s--;
				}		
			}
		cout<<ans<<endll;
	}
}
