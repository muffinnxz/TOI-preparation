#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<queue>
using namespace std;
#define MAX_VALUE 1000
//int matrix[8][8]=
//{
//	{0,9,0,0,4,0,0,0},
//	{9,0,0,0,0,0,0,0},
//	{0,0,0,0,0,3,3,0},
//	{0,0,0,0,0,1,0,2},
//	{4,0,0,0,0,0,0,7},
//	{0,0,3,1,0,0,7,0},
//	{0,0,3,0,0,7,0,1},
//	{0,0,0,2,7,0,1,0}
//};

int matrix[8][8]=
{
	{0,1,4,0},
	{1,0,1,1},
	{4,1,0,0},
	{0,1,0,0},
};

const int n=4;
int weight[n];
int pred[n];
main()
{
	for(int i=0;i<n;i++)
		weight[i]=1000;

	int x,i;
	priority_queue<int> vertex_queue;
	cout<<"Enter the start NODE : ";
	cin>>x;
	weight[x]=0;

	vertex_queue.push(x);

	while(!vertex_queue.empty())
	{
		int u=vertex_queue.top();
		vertex_queue.pop();
		for(i=0;i<n;i++)
			if(matrix[u][i]!=0)
			{
				int nextweight = weight[u]+matrix[u][i];
				if(weight[i]>nextweight)
				{
					weight[i]=nextweight;
					vertex_queue.push(i);
					pred[i]=u;
				}
			}
	}
	
	for(i=0;i<n;i++)
		cout<<weight[i]<<" ";
	cout<<endl;
	
	i=3;
	cout<<i<<" ";
	do
	{
		i=pred[i];
		cout<<i<<" ";
	}while(i!=x);
		
}
