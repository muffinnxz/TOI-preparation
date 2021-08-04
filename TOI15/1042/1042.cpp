#include<iostream>
#include<list>
using namespace std;

main()
{
	int n,m,k;
	cin>>n>>m>>k;
	int x[n+1],y[m+1];
	int i,j;
	for(i=0;i<n;i++)
		x[i]=0;
	for(i=0;i<m;i++)
		y[i]=0;
		
	for(i=0;i<k;i++)
	{
		int a,b,r;
		cin>>a>>b>>r;
		for(j=a-r;j<=a+r;j++)
			if(j<0||j>m) continue;
			else y[j]++;
		for(j=b-r;j<=b+r;j++)
			if(j<0||j>n) continue;
			else x[j]++;
	}
	
	list<int> temp;
	for(i=0;i<n;i++)
		temp.push_back(x[i]);
	for(i=0;i<m;i++)
		temp.push_back(y[i]);
	temp.sort();
	cout<<temp.back();
}
