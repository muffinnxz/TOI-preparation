#include<bits/stdc++.h>
using namespace std;

int process()
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	char board[n][m];
	for(int i=0;i<n;i++)
		cin>>board[i];
	
	int max_wire[m*n][4]={0};
	int temp;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			if(board[i][j]=='1')
			{
				temp=j;
				break;
			}
		for(int j=temp;j<m;j++)
		{
			if(board[i][j]=='0')
			{
				for(int k=temp;k<j;k++)
				{
					max_wire[i*m+k][0]=k-temp;
					max_wire[i*m+k][1]=j-k-1;
				}
				temp=j+1;
			}
			else if(j==m-1)
			{
				j++;
				for(int k=temp;k<j;k++)
				{
					max_wire[i*m+k][0]=k-temp;
					max_wire[i*m+k][1]=j-k-1;
				}
			}
		}
	}
	
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			if(board[j][i]=='1')
			{
				temp=j;
				break;
			}
		for(int j=temp;j<n;j++)
		{
			if(board[j][i]=='0')
			{
				for(int k=temp;k<j;k++)
				{
					max_wire[k*m+i][2]=k-temp;
					max_wire[k*m+i][3]=j-k-1;
				}
				temp=j+1;
			}
			else if(j==n-1)
			{
				j++;
				for(int k=temp;k<j;k++)
				{
					max_wire[k*m+i][2]=k-temp;
					max_wire[k*m+i][3]=j-k-1;
				}	
			}
		}
	}
	
	int max=0;
	for(int i=0;i<n*m;i++)
	{
		sort(max_wire[i],max_wire[i]+4);
		if(max_wire[i][2]+max_wire[i][3]>max) max=max_wire[i][2]+max_wire[i][3];
	}
	
	return max+1;
}

main()
{
	int t;
	cin>>t;
	
	int ans[t];
	for(int i=0;i<t;i++)
		ans[i]=process();
	for(int i=0;i<t;i++)
		cout<<ans[i]<<endl;
}
