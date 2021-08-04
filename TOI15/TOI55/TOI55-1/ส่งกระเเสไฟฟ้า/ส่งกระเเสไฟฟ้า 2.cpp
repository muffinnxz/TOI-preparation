#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int testcase(int x,int n,vector<int> a,int k)
{
	int i,v;
	int temp=0,value=0;
	for(i=0;i<n;i++)
	{
		v=(x&(1<<i))!=0;
		if((i==0&&v==0)||(i==n-1&&v==0)) return 0;
		if(v==1)
		{
			temp=0;
			value+=a[i];
		}
		else temp++;
		if(temp>=k) return 0;
	}
	return value;
}

main()
{
	int n,k,i;
	cin>>n>>k;
	vector<int> v;
	list<int> ans;
	for(i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	int ss=pow(2,n);
	int min;
	for(i=0;i<ss;i++)
	{
		int temp=testcase(i,n,v,k);
		if(temp==0) continue;
		if(i==0) min=temp;
		else if(temp<min) min=temp;
	}
	cout<<min;
}
