#include<stdio.h>
#include<stack>
#include<list>
#include<queue>
#include<iostream>
using namespace std;

main()
{
	int n,A=0,B=0,C=0;
	cin>>n;
	list<int> cmd;
	list<int> ::iterator it;
	int i;
	for(i=0;i<n;i++)
	{
		int x;
		cin>>x;
		cmd.push_back(x);
	}
	for(it=cmd.begin();it!=cmd.end();it++)
	{
		if(A<=B&&A<=C)
		{
			cout<<"A"<<" ";
			A+=*it;
		}
		else if(B<=A&&B<=C)
		{
			cout<<"B"<<" ";
			B+=*it;
		}
		else 
		{
			cout<<"C"<<" ";
			C+=*it;
		}
	}
	
}

