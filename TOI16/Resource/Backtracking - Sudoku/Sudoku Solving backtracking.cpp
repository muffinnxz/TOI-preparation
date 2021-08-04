#include<bits/stdc++.h>
#include<vector>
using namespace std;

int grid[9][9] = {0};

bool isPossible(int y,int x,int n)
{
	for(int i=0;i<9;i++)
		if(grid[y][i]==n || grid[i][x]==n) return false;
	x = (x/3)*3;
	y = (y/3)*3;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(grid[y+i][x+j]==n) return false;
	return true;
}

void print_grid()
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			cout<<grid[i][j]<<" ";
		cout<<endl;
	}
}

int solve()
{
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			if(grid[i][j]==0)
			{
				for(int k=1;k<=9;k++)
					if(isPossible(i,j,k)) 
					{
						grid[i][j]=k;
						solve();
						grid[i][j]=0;
					}
				return 0;
			}
	cout<<endl;		
	print_grid();
	cout<<endl;
	return 0;
}

main()
{
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			cin>>grid[i][j];	
	solve();
}
