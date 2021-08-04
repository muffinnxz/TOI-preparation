#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;


void substing(char s[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=1;i<=n-i;j++)
			cout<< s.substr(i,j) <<endl;
}
main()
{
	int n,m;
	cin>>n>>m;
	char s[n];
	cin>>s;
	cout<<s;
}
