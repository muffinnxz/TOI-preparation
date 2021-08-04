#include<iostream>
#include<list>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

main()
{
	int n,m,c;
	cin>>n;
	char light[n];
	int i;
	for(i=0;i<n;i++)
		light[i]='O';
	cin>>m;
	for(i=0;i<m;i++)
	{
		cin>>c;
		light[c]='X';
		light[c-1]='X';
		light[c-2]='X';
	}
	for(i=0;i<n;i++)
	{
		cout<<light[i];
		if(i!=n-1) cout<<"-";
	}

}
