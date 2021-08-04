#include<stdlib.h>
#include<iostream>
#include<stdio.h>
using namespace std;

main()
{
	int n,m;
	cin>>n>>m;
	int i,j,table[n][n];
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			table[i][j]=0;
			
	for(i=0;i<m;i++)
	{
		char a,b;
		cin>>a>>b;
		table[int(a)-65][int(b)-65]=1;
		table[int(b)-65][int(a)-65]=1;
	}
	
	int sum=0;
	for(i=0;i<n;i++)
		sum+=i;
	int rest=sum-m;
	cout<<rest<<endl;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(i!=j&&table[i][j]==0)
			{
				table[i][j]=1;
				table[j][i]=1;
				printf("%c %c\n",char(i+65),char(j+65));
			}
		}
}
