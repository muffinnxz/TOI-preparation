#include<bits/stdc++.h>
using namespace std;

#define endll "\n"

int land[2001][2001];
int n, m, k;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m>>k;

	memset(land,0,sizeof(land));
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>land[i][j];
	
	int tri_left = 0, tri_right = 0;
	for(int i=1;i<k;i++)
		for(int j=0;j<i;j++)
		{
			tri_left += land[i][j];
			tri_right += land[i][k-2-j];
		}
	
	int last_tri_left = 0, last_tri_right = 0;
	int ans = INT_MIN;
	for(int i=0;i<=n-k;i++)
	{
		last_tri_left = tri_left;
		last_tri_right = tri_right;
		for(int j=0;j<=m-k;j++)
		{
			if(j > 0)
				for(int x=i;x<i+k;x++)
				{
					tri_left -= land[x][j-1];
					tri_right -= land[x][j+k-2-x+i];
				}
			for(int x=i;x<i+k;x++)
			{
				tri_left += land[x][j+x-i];
				tri_right += land[x][j+k-1];
			}
			ans = max(ans, tri_left);
			ans = max(ans, tri_right);
		}
		tri_left = last_tri_left;
		tri_right = last_tri_right;
		for(int x=i+1;x<i+k;x++)
		{
			tri_left = tri_left - land[x][x-i-1] + land[i+k][x-i-1];
			tri_right = tri_right - land[x][k-x+i-1] + land[i+k][k-x+i-1];
		}
	}
	
	cout<<ans;
}
