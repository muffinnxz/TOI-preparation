#include<iostream>
using namespace std;

main()
{
	int l,n;
	cin>>l>>n;
	
	char chain[n][l];
	int i,j;
	
	for(j=0;j<l;j++)
		cin>>chain[0][j];
			
	for(i=1;i<n;i++)
	{
		for(j=0;j<l;j++)
			cin>>chain[i][j];
		int temp=0;
		for(j=0;j<l;j++)
		{
			if(chain[i][j]!=chain[i-1][j]) temp++;
			if(temp>2) break;
		}
		if(temp>2) 
		{
			for(j=0;j<l;j++)
				cout<<chain[i-1][j];
			break;
		}
	}
}
