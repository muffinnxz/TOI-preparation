#include<iostream>
#include<list>
#include<stdio.h>
using namespace std;

main()
{
	list<char> A,B,C;
	list<char>::iterator it;
	int n;
	char x;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		A.push_back(x);
	}
	for(int i=0;i<n;i++)
	{
		cin>>x;
		B.push_back(x);
	}
	for(it=A.begin();it!=A.end();it++)
		C.push_back(*it);
	for(it=B.begin();it!=B.end();it++)
		C.push_back(*it);
	
	C.sort();
	C.unique();
	
	for(it=C.begin();it!=C.end();it++)
		cout<<*it<<" ";
}
