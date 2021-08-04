#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

main()
{
	int a,b;
	cin>>a>>b;
	int temp_a=a*2+1,temp_b=b*2+1;
	int map_water[temp_a][temp_b];
	int i,j;
			
	for(i=0;i<temp_a;i++)
		for(j=0;j<temp_b;j++)
			map_water[i][j]=0;

	for(i=1;i<temp_a;i+=2)
	{
		for(j=1;j<temp_b;j+=2)
		{
			char temp;
			cin>>temp;
			
			map_water[i][j]=1;
			if(temp=='R') 
			{
				map_water[i][j+1]=1;
			}
			else if(temp=='D') 
			{
				map_water[i+1][j]=1;
			}
			else if(temp=='B')
			{
				map_water[i][j+1]=1;
				map_water[i+1][j]=1;
			}
		}
	}
	
	int water_met=0;
	int temp=2;
	map_water[1][1]=temp;
	int time=1;
	while(water_met==0)
	{
		for(i=1;i<temp_a;i+=2)
		{
			if(water_met==1) break;
			for(j=1;j<temp_b;j+=2)
			{
				if(water_met==1) break;
				if(map_water[i][j]==temp)
				{
					if(map_water[i][j+1]==1&&map_water[i][j+2]==1) map_water[i][j+2]=temp+1;
					else if(map_water[i][j+1]==1&&map_water[i][j+2]!=1) 
					{
						map_water[i][j+2]=0;
						water_met=1;
					}
					if(map_water[i+1][j]==1&&map_water[i+2][j]==1) map_water[i+2][j]=temp+1;
					else if(map_water[i+1][j]==1&&map_water[i+2][j]!=1) 
					{
						map_water[i+2][j]=0;
						water_met=1;
					} 		
				}	
			}
		}
		temp++;
		time++;
	}
	
	int map_display[a][b];
	int x=0,y=0;
	
	for(i=1;i<temp_a;i+=2)
	{
		for(j=1;j<temp_b;j+=2)
			if(map_water[i][j]==0)
			{
				x=(i+1)/2;
				y=(j+1)/2;
			} 
	}
	
	cout<<time<<endl<<x<<" "<<y;
}
