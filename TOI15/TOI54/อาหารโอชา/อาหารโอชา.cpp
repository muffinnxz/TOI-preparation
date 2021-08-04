#include<iostream>
#include<list>
#include<math.h>
using namespace std;

list<unsigned long int> ans;

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void permute(int arr[],int l,int r,int n)
{
	int i;
	if(l==r)
	{
		unsigned long int result=0;
		int temp=0;
		for(i=n-1;i>=0;i--)
		{
			result+=arr[temp]*pow(10,i);
			temp++;
		}
		ans.push_back(result);
	}
	else
	{
		for(i=l;i<=r;i++)
		{
			swap(arr[l],arr[i]);
			permute(arr,l+1,r,n);
			swap(arr[l],arr[i]);
		}
	}
}

main()
{
	int n,m;
	cin>>n>>m;
	
	int ban[m];
	int i,j;
	for(i=0;i<m;i++)
		cin>>ban[i];

	int arr[n];
	for(i=0;i<n;i++)
		arr[i]=i+1;
		
	permute(arr,0,n-1,n);
	
	int p=pow(10,n-1);
	int ans_n=ans.size();
	
	list<unsigned long int> display;
	list<unsigned long int>::iterator it;
	
	for(it=ans.begin();it!=ans.end();it++)
	{
		int temp=*it/p;
		int indi=0;
		for(i=0;i<m;i++)
		{
			if(temp==ban[i]) indi=1;
		}
		if(indi==0) display.push_back(*it);
	}
	
	for(it=display.begin();it!=display.end();it++)
	{
		int value=*it;
		int k=p;
		while(k!=0)
		{
			cout<<value/k<<" ";
			value=value%k;
			if(k==1) break;
			k/=10;
		}
		cout<<endl;
	}
}
