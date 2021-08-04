#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

main()
{
	int n;
	float m;
	cin>>n>>m;
	int i,j;
	list<float> v;
	list<float>::iterator it;
	vector<float> o,r;
	char temp;
	o.push_back(0);
	r.push_back(0);
	for(i=1;i<=n;i++)
	{
		cin>>temp;
		if(temp=='O')
		{
			o.push_back(o[i-1]+1);
			r.push_back(r[i-1]);	
		}
		else
		{
			r.push_back(r[i-1]+1);
			o.push_back(o[i-1]);
		}
	}
	for(i=1;i<=n-1;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			float a=o[j]-o[i-1],b=r[j]-r[i-1];
			if(a==0||b==0) continue;
			if(a/b==m) v.push_back(j-i+1);
		}
	}
	v.unique();
	v.sort();
	cout<<v.back();
}
