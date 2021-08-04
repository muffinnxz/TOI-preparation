#include<stdio.h>
#include<iostream>
using namespace std;
main()
{
	int A=0,B=0,C=0;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int d;
		cin>>d;
		if(A<=B&&A<=C)
			{
				cout<<"A"<<endl;
				A+=d;
			}
		else if(B<=A&&B<=C)
			{
				cout<<"B"<<endl;
				B+=d;
			}
		else
			{
				cout<<"C"<<endl;
				C+=d;
			}
	}
}
