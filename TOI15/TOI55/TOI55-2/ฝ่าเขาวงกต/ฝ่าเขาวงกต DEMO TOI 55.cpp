#include<iostream>
#include<queue>
#include<math.h>
using namespace std;

main()
{
	int mazex,mazey;
	int startx,starty;
	int endx,endy;
	int *ptr,*ptr2;
	
	cin>>mazex>>mazey;
	cin>>startx>>starty;
	cin>>endx>>endy;
	
	int maze[mazex+2][mazey+2];
	int i,j;
	for(i=0;i<mazex+2;i++)
		for(j=0;j<mazey+2;j++)
		{
			if(i==0||i==mazex+1||j==0||j==mazey+1) maze[i][j]=0;
			else cin>>maze[i][j];
		}
	
	int nodcount=0;
	
	maze[startx][starty]=2;
	maze[endx][endy]=2;
	
	for(i=1;i<mazex+1;i++)
	{
		for(j=1;j<mazey+1;j++)
		{
			int up=0,down=0,left=0,right=0;
			if(maze[i][j]==1)
			{
				if(maze[i+1][j]!=0) up=1;
				if(maze[i-1][j]!=0) down=1;
				if(maze[i][j+1]!=0)	right=1;
				if(maze[i][j-1]!=0) left=1;
				if((up+down+left+right)==1)
				{
					maze[i][j]=nodcount+3;
					nodcount++;
				}
				else if(up==0&&down==0) maze[i][j]=1;
				else if(left==0&&right==0) maze[i][j]=1;
				else
				{
					maze[i][j]=nodcount+3;
					nodcount++;
				}
			}
		}
	}
	maze[endx][endy]=nodcount+3;
	nodcount+=2;
	
	int matrix[nodcount][nodcount];
	for(i=0;i<nodcount;i++)
		for(j=0;j<nodcount;j++)
			matrix[i][j]=0;
	
	for(i=1;i<mazex+1;i++)
	{
		for(j=1;j<mazey+1;j++)
		{
			if(maze[i][j]>=2)
			{
				int tempx=i,tempy=j;
				ptr=&maze[i][j];
				
				ptr2=ptr;
				while((*ptr2==*ptr||*ptr2==1)&&*ptr2!=0)
				{
					ptr2=&maze[tempx+1][tempy];
					tempx++;
				}
				if(*ptr2!=0) matrix[*ptr-2][*ptr2-2]=abs(tempx-i);
				
				tempx=i; tempy=j;
				ptr2=ptr;
				while((*ptr2==*ptr||*ptr2==1)&&*ptr2!=0)
				{
					ptr2=&maze[tempx-1][tempy];
					tempx--;
				}
				if(*ptr2!=0) matrix[*ptr-2][*ptr2-2]=abs(tempx-i);
				
				tempx=i; tempy=j;
				ptr2=ptr;
				while((*ptr2==*ptr||*ptr2==1)&&*ptr2!=0)
				{
					ptr2=&maze[tempx][tempy+1];
					tempy++;
				}
				if(*ptr2!=0) matrix[*ptr-2][*ptr2-2]=abs(tempy-j);
				
				tempx=i; tempy=j;
				ptr2=ptr;
				while((*ptr2==*ptr||*ptr2==1)&&*ptr2!=0)
				{
					ptr2=&maze[tempx][tempy-1];
					tempy--;
				}
				if(*ptr2!=0) matrix[*ptr-2][*ptr2-2]=abs(tempy-j);
			}
		}
	}
	
	int weight[nodcount];
	priority_queue<int> vertex_queue;
	for(i=0;i<nodcount;i++)
		weight[i]=999999;
	weight[0]=0;
	
	vertex_queue.push(0);
	
	while(!vertex_queue.empty())
	{
		int u=vertex_queue.top();
		vertex_queue.pop();
		for(i=0;i<nodcount;i++)
			if(matrix[u][i]!=0)
			{
				int nextweight=weight[u]+matrix[u][i];
				if(weight[i]>nextweight)
				{
					weight[i]=nextweight;
					vertex_queue.push(i);
				}
			}
	}
	
	cout<<endl;
	for(i=0;i<mazex+2;i++)
	{
		for(j=0;j<mazey+2;j++)
		{
			if(maze[i][j]<10) cout<<maze[i][j]<<"  ";
			else cout<<maze[i][j]<<" ";
		}	
		cout<<endl;
	}
	cout<<endl;	
	for(i=0;i<nodcount;i++)
	{
		for(j=0;j<nodcount;j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<weight[nodcount-1];
}
