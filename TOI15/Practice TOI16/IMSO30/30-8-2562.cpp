#include<iostream>
#include<math.h>
#include <bits/stdc++.h> 
using namespace std;

main()
{
	char n[3];
	char q[5][3]={{'C','A','T'},{'R','A','T'},{'D','O','G'},{'P','I','G'},{'C','O','W'}};
	int qv[5][3];
	int nv[3];
	int dif[5];
	int i,j;
	for(i=0;i<3;i++)
		cin>>n[i];
	for(i=0;i<5;i++)
	{
		for(j=0;j<3;j++)
		{
			qv[i][j]=(int)q[i][j]-64;
		}
	}
	for(i=0;i<3;i++)
		nv[i]=(int)n[i]-64;
	int sum=0;
	for(i=0;i<5;i++)
	{
		int temp=0;
		for(j=0;j<3;j++)
		{
			temp+=abs(nv[j]-qv[i][j]);
		}
		sum+=temp;
	}
	cout<<sum;  
}
