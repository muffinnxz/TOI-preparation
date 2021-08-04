#include<bits/stdc++.h>
using namespace std;

main()
{
	int w,h,n;
	cin>>w>>h>>n;
	
	int window[w]={0};
	
	int x,a;
	for(int i=0;i<n;i++)
	{
		cin>>x>>a;
		for(int j=x;j<x+a;j++)
			if(j>w) break;
			else window[j]++;
	}
	
	int full=0,half=0;
	for(int i=0;i<w;i++)
	{
		if(window[i]==0) full+=h;
		else if(window[i]==1) half+=h;
	}
	cout<<full<<" "<<half;
}
