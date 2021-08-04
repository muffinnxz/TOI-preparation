#include<iostream>
#include<list>
using namespace std;

main()
{
	int m,n,t;
	
	cin>>m>>n>>t;
	
	int road[t+2][m+2];
	int i,j;
	
	
	for(i=0;i<t+2;i++)
		for(j=0;j<m+2;j++)
		{
			if(j==0||i==t+1||j==m+1) road[i][j]=1;
			else if(i==0) road[i][j]=0;
			else cin>>road[i][j];
		}
	
	int x=n,y=0;
	list<int> alg; 
	
	while(y!=t)
	{
		int l=0,r=0,m=0;
		if(road[y+1][x]==0) m=1;
		if(road[y+1][x-1]==0) l=1;
		if(road[y+1][x+1]==0) r=1;
		
		if(m==1)
		{
			road[y][x]=1;
			alg.push_back(3);
			y++;
		}
		else if(l==1)
		{
			road[y][x]=1;
			alg.push_back(1);
			y++;x--;	
		}
		else if(r==1)
		{
			road[y][x]=1;
			alg.push_back(2);
			y++;x++;
		}
		else
		{
			road[y][x]=1;
			int temp=alg.back();
			if(temp==3)
				y--;
			else if(temp==1)
			{
				y--;x++;
			}
			else
			{
				y--;x--;
			}
			alg.pop_back();
		}
	}
	
	list<int>::iterator it;
	for(it=alg.begin();it!=alg.end();it++)
		cout<<*it<<endl;
}
