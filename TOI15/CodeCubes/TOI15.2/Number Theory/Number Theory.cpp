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
	for(i=0;i<m;i++)
		cin>>b[i];
	int move=n-m+1;
	int count=0;
	list<int> list;
	for(i=0;i<move;i++)
	{
		if(a[i]%b[0]==0) list.push_back(i); 
	}
	
	while(!list.empty())
	{
		int temp=list.front();
		list.pop_front();
		int flag=1;
		for(i=0;i<m;i++)
			if(a[temp+i]%b[i]!=0)
			{
				flag=0;
				break;
			}	
		if(flag==1) count++;
	}
	
	
	
//	for(i=0;i<move;i++)
//	{
//		int flag=1;
//		for(j=0;j<m;j++)
//		{
//			if(a[i+j]%b[j]!=0)
//			{
//				flag=0;
//				break;
//			}
//		}
//		if(flag==1) count++;
//	}


	cout<<count;
}
