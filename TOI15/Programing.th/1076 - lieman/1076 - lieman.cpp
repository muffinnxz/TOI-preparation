#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<list>
using namespace std;

list<int> temp;

void showpos(int x,int n)
{
	int v,i;
	for(i=0;i<n;i++)
	{
		v=(x&(1<<i))!=0;
		if(v==1)
			temp.push_back(1);
		else
			temp.push_back(-1);
	}
}

main()
{
	int n,m;
	cin>>n>>m;
	
	int ans[n][m];
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			cin>>ans[i][j];
	
	int alln=pow(2,m);
	int corans[alln][m];

	for(i=0;i<alln;i++)
	{
		showpos(i,m);
		for(j=0;j<m;j++)
		{
			corans[i][j]=temp.front();
			temp.pop_front();
		}
	}
	
	int min_lie;
	for(i=0;i<alln;i++)
	{
		int lie=0;
		for(k=0;k<n;k++)
		{
			int temp=0;
			for(j=0;j<m;j++)
			{
				if(ans[k][j]!=corans[i][j]&&ans[k][j]!=0) temp++;
				if(temp!=0) break;
			}
			if(temp!=0) lie++; 
		}
		
		if(i==0) min_lie=lie;
		else if(lie<min_lie) min_lie=lie;
	}
	
	cout<<min_lie;
}
