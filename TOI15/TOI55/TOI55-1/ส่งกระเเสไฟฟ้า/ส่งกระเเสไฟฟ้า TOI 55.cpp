#include<iostream>
#include<list>
#include<math.h>
using namespace std;

list<int> allpos;

void alp(int x,int n,int k)
{
	list<int> pdata;
	int v,i,czero=0;
	for(i=0;i<n;i++)
	{
		v=(x&(1<<i))!=0;
		if(i==0&&v!=1) break;
		if(v==1) 
		{
			czero=0;
			pdata.push_back(1);
		}
		else
		{
			czero++;
			pdata.push_back(0);
		}
		if(czero>=k) break;
	}
	if(czero<k&&pdata.front()==1&&pdata.back()==1)
	{
		int sum=0;
		for(i=0;i<n;i++)
		{
			sum+=pdata.back()*pow(10,i);
			pdata.pop_back();
		}
		allpos.push_back(sum);
	}	
}
main()
{
	int n,k;
	cin>>n;
	cin>>k;
	int p[n],i;
	for(i=0;i<n;i++)
		cin>>p[i];
	int aln=pow(2,n);
	for(i=0;i<aln;i++)
		alp(i,n,k);
	int	allpossize=allpos.size();
	int mincost;
	for(i=0;i<allpossize;i++)
	{
		int sumcost=0,state=allpos.front();
		allpos.pop_front();
		int j;
		for(j=n-1;j>=0;j--)
		{
			if(state%10==1) sumcost+=p[j];
			state/=10;
		}
		if(i==0) mincost=sumcost;
		if(sumcost<=mincost) mincost=sumcost;
	}
	cout<<mincost;
}
