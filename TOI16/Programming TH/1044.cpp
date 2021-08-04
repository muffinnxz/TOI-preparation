#include<bits/stdc++.h>
using namespace std;

main()
{
	int n,m;
	cin>>n>>m;

	int all_sum = 0;
	int price_road[n][m],up_price[n][m];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin>>price_road[i][j];
			all_sum+=price_road[i][j];
		}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>up_price[i][j];
	
	int sum_row[n],sum_col[m];
	for(int i=0;i<n;i++)
	{
		int sum = 0;
		for(int j=0;j<m;j++)
			sum+=price_road[i][j];
		sum_row[i] = sum;
	}
	for(int i=0;i<m;i++)
	{
		int sum = 0;
		for(int j=0;j<n;j++)
			sum+=price_road[j][i];
		sum_col[i] = sum;
	}
	
	int sum_upr[n],sum_upc[m];
	for(int i=0;i<n;i++)
	{
		int sum = 0;
		for(int j=0;j<m;j++)
			sum+=up_price[i][j];
		sum_upr[i] = sum;
	}
	for(int i=0;i<m;i++)
	{
		int sum = 0;
		for(int j=0;j<n;j++)
			sum+=up_price[j][i];
		sum_upc[i] = sum;
	}

	int max = 0;
	for(int i=0;i<n;i++)
	{
		if(i==0 && all_sum - sum_row[i] + sum_upr[i+1] > max) max =  all_sum - sum_row[i] + sum_upr[i+1];
		else if(i==n-1 && all_sum - sum_row[i] + sum_upr[i-1] > max) max =  all_sum - sum_row[i] + sum_upr[i-1];
		else if(i!=0 && i!=n-1 && all_sum - sum_row[i] + sum_upr[i-1] + sum_upr[i+1] > max) max = all_sum - sum_row[i] + sum_upr[i-1] + sum_upr[i+1];
	}
	for(int i=0;i<m;i++)
	{
		if(i==0 && all_sum - sum_col[i] + sum_upc[i+1] > max) max = all_sum - sum_col[i] + sum_upc[i+1];
		else if(i==m-1 && all_sum - sum_col[i] + sum_upc[i-1] > max) max = all_sum - sum_col[i] + sum_upc[i-1];
		else if(i!=0 && i!=m-1 && all_sum - sum_col[i] + sum_upc[i-1] + sum_upc[i+1] > max) max = all_sum - sum_col[i] + sum_upc[i-1] + sum_upc[i+1];
	}
	if(n==1 && n==1) cout<<0;
	else cout<<max;
}
