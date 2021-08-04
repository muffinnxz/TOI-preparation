#include<stdio.h>
#include<iostream>
#include<queue>
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
queue<int> BFSq;
int c=0;
BFS(int i)
{
	int j;
	visit[i]=1;
	c++;
	if(c<n)
	{
	for(j=0;j<n;j++)
		if(!visit[j]&&table[i][j]==1)
		{
			BFSq.push(j);
		}
	cout<<BFSq.front()<<endl;
	BFSq.pop();
	BFS(BFSq.front());
	}
}
main()
{
	int i,j;
	for(i=0;i<n;i++)
		visit[i];
	BFSq.push(0);
	BFS(0);
}
