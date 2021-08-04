#include<bits/stdc++.h>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m,k;
	cin>>n>>m>>k;
	
	int land[n][m];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>land[i][j];
	
	int maxsum = 0;
	
	int row_sum[n];
	for(int i=0;i<n;i++)
		row_sum[i] = 0;
	
	for(int i=0;i<k-1;i++)
		for(int j=0;j<n;j++)
			row_sum[j] += land[j][i];
		
	for(int i=k-1;i<m;i++)
	{
		for(int j=0;j<n;j++)
			row_sum[j] += land[j][i];
		
		int tmp = 0;
		for(int j=0;j<k-1;j++)
			tmp += row_sum[j];
		for(int j=k-1;j<n;j++)
		{
			tmp += row_sum[j];
			if(tmp > maxsum) maxsum = tmp;
			tmp -= row_sum[j-k+1];
		}
		
		for(int j=0;j<n;j++)
			row_sum[j] -= land[j][i-k+1];
	}
	
	cout<<maxsum;
}
