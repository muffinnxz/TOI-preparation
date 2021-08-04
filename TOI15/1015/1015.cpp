#include<iostream>
#include<vector>
using namespace std;

int countfield(int x,int y,int start,vector<int> v[])
{
	if(v[x][y]==-1) return 0;

	if(v[x][y]==start) 
	{
		int temp=1;
		v[x][y]=-1;
		temp+=countfield(x,y+1,start,v);
		temp+=countfield(x,y-1,start,v);
		temp+=countfield(x+1,y,start,v);
		temp+=countfield(x-1,y,start,v);
		return temp;	
	}
}

main()
{
	int n,i,j;
	cin>>n;
	vector<int> v[n+2];
	for(i=0;i<n+2;i++)
	{
		v[0].push_back(-1);
		v[n+1].push_back(-1);	
	}
		
	for(i=1;i<n+1;i++)
	{
		for(j=0;j<n+2;j++)
		{
			if(j==0||j==n+1) v[i].push_back(-1);
			else
			{
				int temp;
				cin>>temp;
				v[i].push_back(temp);	
			}
		}
	}
	int count=0;
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<n+1;j++)
		{	
			if(v[i][j]==-1||v[i][j]==0) continue;
			int a=v[i][j];
			int check=0;
			if(v[i][j+1]==a&&v[i+1][j]==a) check++;
			if(v[i][j+1]==a&&v[i-1][j]==a) check++;
			if(v[i][j-1]==a&&v[i+1][j]==a) check++;
			if(v[i][j-1]==a&&v[i-1][j]==a) check++;
			if(check!=1) continue;
			else if(countfield(i,j,a,v)==3) count++;
		}
	}			
	cout<<count;
}
