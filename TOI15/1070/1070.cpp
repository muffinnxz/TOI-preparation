#include<iostream>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

main()
{
	int n,i;
	cin>>n;
	vector<int> v(n);
	for(i=0;i<n;i++)
		cin>>v[i];
	sort(v.begin(),v.end());
	if((n<3)||(v[0]+v[1]>v[n-1])) cout<<"no";
	else cout<<"yes";
}
