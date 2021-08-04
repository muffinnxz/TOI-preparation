#include<iostream>
#include<list>
using namespace std;

main()
{
	int n,m,q;
	int i,j;
	cin>>n>>m>>q;
	int magnet[n]={0};
	int question[q];
	for(i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;a--;
		for(j=a;j<=a+b-1;j++)
		{
			if(magnet[j]==0) magnet[j]=1;
			else magnet[j]=0;	
		}
	}
	
	for(i=0;i<q;i++)
		cin>>question[i];
	
	int flag=0;
	for(i=0;i<q;i++)
	{
		int *ptr=&magnet[question[i]-1];
		int magc=1;
		while(flag!=1)
		{
			if(*(ptr+1)==*ptr) 
			{
				magc++;
				ptr++;
			}
			else break;
		}
		ptr=&magnet[question[i]-1];
		while(flag!=1)
		{
			if(*(ptr-1)==*ptr) 
			{
				magc++;
				ptr--;
			}
			else break;
		}
		cout<<magc<<endl;
	}
}
