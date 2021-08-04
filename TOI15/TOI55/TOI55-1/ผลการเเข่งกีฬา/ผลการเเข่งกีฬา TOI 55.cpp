#include<iostream>
#include<math.h>
#include<list>
#include<string.h>
using namespace std;

int k,a,b;
list<int> fin;

void ppos(int x,int n)
{
	list<int> z;
	int i,v;
	for(i=0;i<n;i++)
	{
		v=(x&(1<<i))!=0;
		if(v==1)
		{
			a++;
			if(a<=k) z.push_back(1);
		}
		else
		{
			b++;
			if(b<=k) z.push_back(2);;
		}
		if(a==k||b==k) break;
	}
	int zs=z.size();
	int sum=0;
	for(i=0;i<zs;i++)
	{
		sum=sum+(z.back()*pow(10,i));
		z.pop_back();
	}
	fin.push_back(sum);
}

main()
{
	cin>>k;
	cin>>a;
	cin>>b;
	int n=2*k-1;
	int i,tempa=a,tempb=b;
	int alln=pow(2,n-a-b);
	for(i=0;i<alln;i++)
	{
		ppos(i,n);
		a=tempa;
		b=tempb;
	}
	fin.sort();
	fin.unique();
	list<int>::iterator it;
	list<char>::iterator itch;
	list<char> outp;
	for(it=fin.begin();it!=fin.end();it++)
	{
		while(*it!=0)
		{
			if(*it%10==1) outp.push_front('W');
			else outp.push_front('L');
			*it/=10;
		}
		while(!outp.empty())
		{
			cout<<outp.front()<<" ";
			outp.pop_front();
		}
		cout<<endl;
	}
}

