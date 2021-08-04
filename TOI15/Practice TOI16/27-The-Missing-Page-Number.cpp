#include<iostream>
using namespace std;

int d[5000]={0};
int sum_seq(int n)
{
	if(n==1)
	{
		d[n]=1;
		return 1;
	}
	else
	{
		if(d[n]!=0) return d[n];
		else 
		{
			d[n]=sum_seq(n-1)+n;
			return d[n];
		}
	}
}
main()
{
	int n;
	cin>>n;
	int ans=0;
	bool x=false;
	int i=10;
	int j;
	while(!x)
	{
		for(j=2;j<=n;j+=2)
		{
			int temp=sum_seq(j);
			if(n+i>temp) continue;
			else if(n+i==temp)
			{
				ans=(i/4)-1;
				x=true;
				break;
			}
			else break;
		}
		i+=8;
	}
	for(int j=0;j<4;j++)
	{
		cout<<ans+j;
		if(j!=3) cout<<",";
	}
}
