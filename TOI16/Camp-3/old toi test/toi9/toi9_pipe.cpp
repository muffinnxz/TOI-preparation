#include<bits/stdc++.h>
#define endll "\n"
using namespace std;

int n, m, pipe[301][301];
list<int> pipeline;

void flood(int x, int y, int len, char dir)
{	
	if(x < 0 || x >= n || y < 0 || y >= m) 
	{
		pipeline.push_back(len);
		return;
	}
	
	if(dir == 'l')
	{
		if(pipe[x][y] == 11) flood(x-1, y, len+1, 'd');
		else if(pipe[x][y] == 13) flood(x+1, y, len+1, 'u');
		else flood(x, y+1, len+1, 'l');
	}
	else if(dir == 'r')
	{
		if(pipe[x][y] == 12) flood(x-1, y, len+1, 'd');
		else if(pipe[x][y] == 14) flood(x+1, y, len+1, 'u');
		else flood(x, y-1, len+1, 'r');
	}
	else if(dir == 'u')
	{
		if(pipe[x][y] == 11) flood(x, y-1, len+1, 'r');
		else if(pipe[x][y] == 12) flood(x, y+1, len+1, 'l');
		else flood(x+1, y, len+1, 'u');
	}
	else
	{
		if(pipe[x][y] == 13) flood(x, y-1, len+1, 'r');
		else if(pipe[x][y] == 14) flood(x, y+1, len+1, 'l');
		else flood(x-1, y, len+1, 'd');
	}
	
	if(pipe[x][y]/10 != 3) pipe[x][y] = 0;
	else if(dir == 'l' || dir == 'r') pipe[x][y] = 21;
	else pipe[x][y] = 22;

	return;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>pipe[i][j];
	
	for(int i=0;i<m;i++)
		if(pipe[0][i] == 11 || pipe[0][i] == 12 || pipe[0][i] == 21 || pipe[0][i] == 31) flood(0, i, 0, 'u');
	for(int i=0;i<m;i++)	
		if(pipe[n-1][i] == 13 || pipe[n-1][i] == 14 || pipe[n-1][i] == 21 || pipe[n-1][i] == 31) flood(n-1, i, 0, 'd');
	for(int i=0;i<n;i++)
		if(pipe[i][0] == 11 || pipe[i][0] == 13 || pipe[i][0] == 22 || pipe[i][0] == 31) flood(i, 0, 0, 'l');
	for(int i=0;i<n;i++)	
		if(pipe[i][m-1] == 12 || pipe[i][m-1] == 14 || pipe[i][m-1] == 22 || pipe[i][m-1] == 31) flood(i, m-1, 0, 'r');	
	
	cout << pipeline.size() << endll;
	for(auto x:pipeline) cout << x << " ";
}
