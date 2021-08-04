using namespace std;
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string>
#include<list>
#include<stack>
main()
{
	int n=5;
	int stack[n];
	int stackre[n];
	int *zero=&stack[-1];
	int *max=&stack[n-1];
	int *top=zero;
	int i;
	if(top==zero)
	{
		for(i=1;i<=n;i++)
		{
			top++;
			*top=i;
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<stack[i]<<" ";
	}
	cout<<endl;
	if(top==max)
	{
		for(i=0;i<n;i++)
		{
			stackre[i]=*top;
			top--;
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<stackre[i]<<" ";
	}
}
