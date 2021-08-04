#include<stdio.h>
#include<iostream>
using namespace std;

int table[7][7]=
			{{0,0,1,0,1,0},
			{0,0,1,0,0,1},
			{1,1,0,1,0,1},
			{0,0,1,0,0,1},
			{0,0,1,0,0,},
			{1,0,0,0,0,1},
			{0,1,1,1,1,0}};
int visit[7],n=7;
			
DFS(int i)
{
	int j;
	cout<<i<<endl;
	visit[i]=1;
	for(j=0;j<n;j++)
		if(!visit[j]&&table[i][j]==1)
			DFS(j);
}
main()
{
	int i,j;
	for(i=0;i<n;i++)
		visit[i]=0;
	DFS(0);
}
