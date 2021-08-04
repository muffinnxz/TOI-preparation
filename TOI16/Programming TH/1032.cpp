#include<bits/stdc++.h>
using namespace std;

bool check_prob(int a[][9],int b[][9])
{
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			if(a[i][j]!=0&&a[i][j]!=b[i][j]) return false;
	return true; 
}

bool check_solve(int a[][9])
{
	int sum_row=0,sum_col=0,sum_box=0;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			sum_row+=a[i][j];
			sum_col+=a[j][i];
		}
		if(sum_row!=45||sum_col!=45) return false;
		sum_row=0;
		sum_col=0;
	}
	for(int x=0;x<3;x++)
		for(int y=0;y<3;y++)
		{
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					sum_box+=a[x*3+i][y*3+j];
			if(sum_box!=45) return false;
			sum_box=0;
		}
			
	return true;
}

main()
{
	int n;
	cin>>n;
	
	int prob_grid[9][9];
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			cin>>prob_grid[i][j];
	
	int solve_grid[9][9];
	for(int t=0;t<n;t++)
	{
		for(int i=0;i<9;i++)
			for(int j=0;j<9;j++)
				cin>>solve_grid[i][j];
		if(check_prob(prob_grid,solve_grid)&&check_solve(solve_grid)) cout<<t+1<<endl;
	}
	cout<<"END";
}
