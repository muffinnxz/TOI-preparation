#include<iostream>
using namespace std;

int swap(int*a,int*b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

main()
{
	int n,m;
	cin>>n>>m;
	int i,j;
	unsigned long long int card[n][2];
	for(i=0;i<n;i++)
		cin>>card[i][0]>>card[i][1];
	for(i=0;i<m;i++)
	{
		int temp;
		cin>>temp;
		for(j=0;j<n;j++)
			if(card[j][0]<=temp) swap(card[j][0],card[j][1]);
	}
	for(i=0;i<n;i++)
		cout<<card[i][0]<<endl;
}
