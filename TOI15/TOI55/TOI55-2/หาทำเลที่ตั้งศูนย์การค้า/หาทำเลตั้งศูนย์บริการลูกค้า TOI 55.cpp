#include<iostream>
using namespace std;

int m,n,k;
int areacost(int x,int y,int *arr)
{
	int i,j,sum=0;
	for(i=x;i<x+k;i++)
	{
		for(j=y;j<y+k;j++)
		{
			sum+=*(arr+i*n+j);
		}
	}
	return sum;
}

main()
{
	cin>>m>>n>>k;
	int field[m][n];
	int i,j;
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			cin>>field[i][j];
	int maxcost=0;
	for(i=0;i<m-k+1;i++)
	{
		for(j=0;j<n-k+1;j++)
		{
			int temp=areacost(i,j,(int*)field);
			if(temp>=maxcost) maxcost=temp;
		}
	}
	cout<<maxcost;
}
