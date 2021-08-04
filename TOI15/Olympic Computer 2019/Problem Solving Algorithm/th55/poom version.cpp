#include<stdio.h>
#include<iostream>
using namespace std;

main()
{
	int p,i;
	
	cin>>p;
	int x[2*p];
	
	for(i=0;i<2*p;i++)
		cin>>x[i];
		
	int odd=0,even=0;
	int lpo=p,lpe=p;
	
	for(i=0;i<2*p;i++)
	{
		if(x[i]%2==0)
		{
			odd=0;
			even++;
			if(even<3) lpo--;
			else lpo-=3;
		}
		else
		{
			even=0;
			odd++;
			if(odd<3) lpe--;
			else lpe-=3;
		}
		if(lpo<=0)
		{
			printf("0\n%d",x[i]);
			break;
		}
		if(lpe<=0)
		{
			printf("1\n%d",x[i]);
			break;
		}
	}
}
