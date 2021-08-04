#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


bool sortcol( const vector<int>& v1,const vector<int>& v2 ) 
{ 
	return v1[0] < v2[0]; 
} 			

main()
{
	int n;
	cin>>n;
	int i,j;
	vector< vector<int> > v;
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			int temp;
			cin>>temp;
			v[i][j]=temp;	
		}
	}
	sort(v.begin(),v.end(),sortcol); 
	int check;
	for(i=0;i<n;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<v[i][j]<<" ";	
		}
		cout<<endl;
	}
}
