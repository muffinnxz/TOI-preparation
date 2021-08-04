#include<iostream>
#include<math.h>
using namespace std;

main()
{
	int n;
	cin>>n;
	
	int i;
	char code[n],temp;
	int dist[n];
	for(i=0;i<n;i++)
		cin>>code[i]>>temp>>dist[i];	
	char face='E';
	int x=0,y=0;
	for(i=0;i<n;i++)
	{
		if(face=='N')
		{
			if(code[i]=='F') 
			{
				x+=dist[i];face='N';
			}
			else if(code[i]=='B')
			{
				x-=dist[i];face='S';	
			} 
			else if(code[i]=='R')
			{
				y+=dist[i];face='E';
			}
			else
			{
				y-=dist[i];face='W';
			}	
		}
		else if(face=='S')
		{
			if(code[i]=='F') 
			{
				x-=dist[i];face='S';
			}
			else if(code[i]=='B')
			{
				x+=dist[i];face='N';	
			} 
			else if(code[i]=='R')
			{
				y-=dist[i];face='W';
			}
			else
			{
				y+=dist[i];face='E';
			}	
		}
		else if(face=='E')
		{
			if(code[i]=='F') 
			{
				y+=dist[i];face='E';
			}
			else if(code[i]=='B')
			{
				y-=dist[i];face='W';	
			} 
			else if(code[i]=='R')
			{
				x-=dist[i];face='S';
			}
			else
			{
				x+=dist[i];face='N';
			}	
		}
		else
		{
			if(code[i]=='F') 
			{
				y-=dist[i];face='W';
			}
			else if(code[i]=='B')
			{
				y+=dist[i];face='E';	
			} 
			else if(code[i]=='R')
			{
				x+=dist[i];face='N';
			}
			else
			{
				x-=dist[i];face='S';
			}	
		}
		if(x>=50000||x<=-50000||y>=50000||y<=-50000) break;
	}
	
	if(x>=50000||x<=-50000||y>=50000||y<=-50000)
		cout<<"DEAD";
	else cout<<y<<" "<<x<<endl<<face;
}
