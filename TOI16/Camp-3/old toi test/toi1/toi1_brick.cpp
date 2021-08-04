#include<bits/stdc++.h>
using namespace std;

#define endll "\n"

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	char board[n][m];
	for(int i=0;i<n;i++)
			cin>>board[i];
	
	int tmp,j;
	for(int i=0;i<m;i++)
	{
		cin>>tmp;
		j = 0;
		while(board[j][i] != 'O' && j < n) j++;
		while(tmp-- && j >= 0) board[--j][i] = '#';
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout<<board[i][j];
		cout<<endll;
	}
}
