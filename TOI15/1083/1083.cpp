#include<iostream>
#include<vector>
#include<list>
#include<math.h>
using namespace std;

long long testcase(long long x,long long size,vector<long long> &v)
{
	long long i,sizec=size;
	list<long long> temp;
	while(x!=0)
	{
		temp.push_front(x%3);
		x=(x-(x%3))/3;
		size--;
	}
	if(size>0) for(i=0;i<size;i++) temp.push_front(0);
	int wallet=0,profit=0;
	for(i=0;i<sizec;i++)
	{
		int a=temp.front();
		temp.pop_front();
		if(a==1) wallet+=v[i];
		else if(a==2) 
		{
			if(v[i]-wallet>0&&wallet!=0) 
			{
				profit+=v[i]-wallet;
				wallet=0;
			}
			else wallet=0;
		}
		else continue;
	}
	return profit;
}

main()
{
	long long n,m,i,j;
	cin>>n;
	vector<long long> price;
	for(i=0;i<n;i++)
	{
		long long temp;
		cin>>temp;
		price.push_back(temp);
	}
	cin>>m;
	vector<long long> sizeq,allpq;
	vector<long long> v[m];

	for(i=0;i<m;i++)
	{
		long long a,b;
		cin>>a>>b;
		a--;b--;
		for(j=a;j<=b;j++)
			v[i].push_back(price[j]);
		sizeq.push_back(b-a+1);
		allpq.push_back(pow(3,sizeq[i]));	
	}
	list<long long> allpr;
	for(i=0;i<m;i++)
	{
		for(j=0;j<allpq[i]-1;j++)
			allpr.push_back(testcase(j,sizeq[i],v[i]));
		allpr.sort();
		cout<<allpr.back()<<endl;
		allpr.clear();
	}
}
