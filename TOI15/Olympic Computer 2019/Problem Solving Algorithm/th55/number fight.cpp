#include<stdio.h>
#include<iostream>
using namespace std;

main()
{
	int p,i;
	
	cin>>p;
	int x[2*p+1];
	
	x[2*p]=2;
	
	for(i=0;i<2*p;i++)
	{
		cin>>x[i];
		if(x[i]%2==1) x[i]=1;
		else x[i]=0;
	}
	
	cout<<"\n";
	
	int *p1=&x[0];
	int *p2=p1;
	int lp0=p,lp1=p,ll;
	while(*p1!=2)
	{
		int c=0;
		while(*p1==*p2)
		{
			p1++;
			c++;
		}
		if(*p2%2==1)
		{
			if(c<3) lp0=lp0-c;
			else  lp0=lp0-2-((c-2)*3);
			if(lp0<=0)
			{
				ll=lp0;
				printf("W1");
				goto e;
			}
		}
		else
		{
			if(c<3) lp1-=c;
			else  lp1-=2+((c-2)*3);
			if(lp1<=0)
			{
				ll=lp1;
				printf("W0");
				goto e;
			}
		}
		p2=p1;
	}
	e:printf("\nz");
}
