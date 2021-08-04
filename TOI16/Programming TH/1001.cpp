#include<iostream>
using namespace std;

main()
{
	int n,m;
	cin>>n>>m;
	int i,j;
	char game[n][m];
	int obs[m];
	for(i=0;i<m;i++)
		obs[i]=n;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			cin>>game[i][j];
			if(obs[j]==n&&game[i][j]=='O') obs[j]=i;
		}
			
	int block[m];
	for(i=0;i<m;i++)
		cin>>block[i];
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<block[i];j++)
		{
			if(obs[i]-j-1<0) break;
			game[obs[i]-j-1][i]='#';
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cout<<game[i][j];
		}
		cout<<endl;
	}

}
