#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int counting(int a)
{
	int c=1;
	while(a!=1)
		{
			if(a%2==1) a=(3*a)+1;
			else a=a/2;
			c++;
		}
	return c;
}

main()
{
	int a,b,x,i;
	cin>>a;
	cin>>b;
	x=counting(a);
	for(i=a+1;i<=b;i++)
	{
		if(x<counting(i)) x=counting(i);
	}
	cout<<x;
	
}
