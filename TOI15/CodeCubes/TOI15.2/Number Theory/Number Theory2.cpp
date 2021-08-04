#include<iostream>
#include<list>
using namespace std;

main()
{
	int n,m;
	cin>>n>>m;
	int i,j;
	int a[n],b[m];
	for(i=0;i<n;i++)
		cin>>a[i];
	int allb=1;
	for(i=0;i<m;i++)
	{
		cin>>b[i];
		allb*=b[i];
	}
	int move=n-m+1;
	int count=0;
	list<int> list;
	for(i=0;i<move;i++)
	{
		int ans=1;
		for(j=i;j<i+m;j++)
			ans*=a[j];
		if(ans%allb==0) list.push_back(i);
	}
	while(!list.empty())
	{
		int flag=1;
		int temp=list.front();
		list.pop_front();
		for(i=0;i<m;i++)
		{
			if(a[temp+i]%b[i]!=0)
			{
				flag=0;
				break;
			} 
		}
		if(flag==1) count++;
	}
	cout<<count;
}
