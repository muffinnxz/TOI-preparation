#include<bits/stdc++.h>
using namespace std;

bool check_work(int work[],int m)
{
	for(int i=0;i<m;i++)
		if(work[i]==0) return false;
	return true;
}

main()
{
	int n,m;
	cin>>n>>m;
	
	int item_price[n],item_work[n][m];
	for(int i=0;i<n;i++)
	{
		cin>>item_price[i];
		for(int j=0;j<m;j++)
			cin>>item_work[i][j];
	}
	
	int state_s = pow(2,n);
	int ans=INT_MAX;
	for(int i=0;i<state_s;i++)
	{
		int x = i;
		int total_price = 0 , work[m] = {0};
		for(int j=0;j<n;j++)
		{
			if(x%2==1)
			{	
				total_price += item_price[j];
				for(int k=0;k<m;k++)
					if(item_work[j][k]==1) work[k] = 1;
			}
			x/=2;
		}
		if(check_work(work,m)) ans=min(ans,total_price);	
	}
	cout<<ans;
}
