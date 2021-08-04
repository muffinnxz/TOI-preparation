#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

main()
{
	int n,m,i;
	char xa,xb;
	list<char> a,b,c;
	list<char>::iterator it;
	list<char>::iterator it2;
	cout<<"Enter n : ";
	cin>>n;
	cout<<"Enter m : ";
	cin>>m;
	cout<<"Enter a : ";
	
	for(i=0;i<n;i++)
	{
		cin>>xa;
		a.push_back(xa);
	}
	cout<<"Enter b : ";
	for(i=0;i<m;i++)
	{
		cin>>xa;
		b.push_back(xa);
	}
	
	for(it=a.begin();it!=a.end();it++)
		c.push_back(*it);
	for(it=b.begin();it!=b.end();it++)
		c.push_back(*it);
		
	c.sort();
	c.unique();
	
	cout<<endl<<"c = ";
	for(it=c.begin();it!=c.end();it++)
		cout<<*it<<" ";

	
}
