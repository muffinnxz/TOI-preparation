#include<bits/stdc++.h>
#include<vector>
using namespace std;

bool check_sqMech(vector<int> sum,int n)
{
	int temp=sum[0];
	for(int i=1;i<(n+1)*2;i++)
		if(sum[i]!=temp) return false;
	return true;
}
main()
{
	int n;
	cin>>n;
	int temp;
	bool flag=false;
	vector<int> sum((n+1)*2,0);
	vector<bool> set(n*n+1,false);

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>temp;
			if(set[temp]) flag=true;
			else set[temp]=true;
			if(i==j)
			{
				sum[n*2]+=temp;
				sum[n*2+1]+=temp;
				sum[i]+=temp;
				sum[n+j]+=temp;
			}
			else
			{
				sum[i]+=temp;
				sum[n+j]+=temp;
			}
		}
	}
	int num=sum[0];
	if(!flag&&check_sqMech(sum,n)) cout<<"Yes";
	else cout<<"No";
}
