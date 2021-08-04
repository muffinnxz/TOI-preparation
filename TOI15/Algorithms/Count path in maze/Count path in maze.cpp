#include<iostream>
#include<math.h>
using namespace std;

main()
{
	int x,y,i,j,ans;
	cin>>x>>y;
	
	int maze[x][y];
	for(i=0;i<x;i++)
		for(j=0;j<y;j++)
			cin>>maze[i][j];
			
	if(maze[0][0]==1)
		goto pri;
		
	for(i=0;i<x;i++)
	{
		if(maze[i][0]==0) maze[i][0]=-1;
		else break;
	}
	for(i=1;i<y;i++)
	{
		if(maze[0][i]==0) maze[0][i]=-1;
		else break;
	}
	for(i=1;i<x;i++)
	{
		for(j=1;j<y;j++)
		{
			if(maze[i][j]==1) continue;
			if(maze[i-1][j]<0) maze[i][j]=(maze[i][j]+maze[i-1][j]);
			if(maze[i][j-1]<0) maze[i][j]=(maze[i][j]+maze[i][j-1]);
		}
	}
	pri:
	ans=(maze[x-1][y-1]<0)?maze[x-1][y-1]:0;
	cout<<abs(ans);
}
