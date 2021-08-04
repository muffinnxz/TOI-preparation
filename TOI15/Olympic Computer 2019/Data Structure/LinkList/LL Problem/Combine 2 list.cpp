#include<iostream>
#include<list>
using namespace std;
main()
{
	list<int> a,b,c;
	list<int>::iterator it;
	int n,ma,mb,mc,i;
	
	cout<<"Enter n : ";
	cin>>n;
	cout<<endl;
	cout<<"Enter a : ";
	for(i=0;i<n;i++)
	{
		cin>>ma;
		a.push_back(ma);
	}
	cout<<"Enter b : ";
	for(i=0;i<n;i++)
	{
		cin>>mb;
		b.push_back(mb);
	}
	for(it=a.begin();it!=a.end();it++)
		c.push_back(*it);
	for(it=b.begin();it!=b.end();it++)
		c.push_back(*it);
	cout<<endl<<"c = ";
	for(it=c.begin();it!=c.end();it++)
		cout<<*it<<" ";
}
