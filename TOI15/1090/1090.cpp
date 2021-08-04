#include<iostream>
#include<vector>
using namespace std;

main()
{
	unsigned long long n,m,i;
	vector<unsigned long long> v;
	cin>>n;
	for(i=0;i<200004;i++)
		v.push_back(0);
	for(i=0;i<n;i++)
	{
		unsigned long long temp;
		cin>>temp;
		v[temp]++;
	}
	cin>>m;
	unsigned long long count=0;
	for(i=0;i<=m/2;i++)
	{
		if(i==m/2 && m%2==0) count+=v[i]*(v[i]-1)/2;
		else count+=v[i]*v[m-i];
	}
	cout<<count;
}
