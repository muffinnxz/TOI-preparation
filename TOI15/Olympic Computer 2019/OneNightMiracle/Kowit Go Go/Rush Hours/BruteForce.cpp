#include<iostream>
#include<math.h>
using namespace std;

void allpos(int x,int n)
{
	int v,i;
	for(i=0;i<n;i++)
	{
		v=(x&(1<<i))!=0;
		if(v==1) cout<<"1 ";
		else cout<<"0 ";
	}
	cout<<endl;
}

main()
{
	int n,i;
	cin>>n;
	int alln=pow(2,n);
	for(i=0;i<alln;i++)
		allpos(i,n);
}
