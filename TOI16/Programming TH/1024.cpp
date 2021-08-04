#include<bits/stdc++.h>
using namespace std;

main()
{
	int n;
	cin>>n;
	
	int l,r;
	int m=INT_MAX;
	int temp;
	int sum[n];
	
	cin>>temp;
	sum[0]=temp;
	for(int i=1;i<n;i++)
	{
		cin>>temp;
		sum[i]=sum[i-1]+temp;
	}
	
	//for(int i=0;i<n;i++)
	//	cout<<sum[i]<<" ";
	//cout<<endl;
	
	for(int i=0;i<n-2;i++)
	{
		for(int j=n-1;j>i+1;j--)
		{
			if(abs( max(sum[i],max(sum[n-1]-sum[j-1],sum[j-1]-sum[i])) -min(sum[i],min(sum[n-1]-sum[j-1],sum[j-1]-sum[i])) )<m)
			{
				m=abs( max(sum[i],max(sum[n-1]-sum[j-1],sum[j-1]-sum[i])) -min(sum[i],min(sum[n-1]-sum[j-1],sum[j-1]-sum[i])) );
				l=i+2;
				r=j+1;
			}
		}
	}
	
	//cout<<m<<endl;
	cout<<l<<" "<<r;
}
