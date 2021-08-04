#include<bits/stdc++.h>
using namespace std;

int temp=0;

int cal_arrage(int n,int x)
{
	if(n>x) return 0;
	
	if(n==x)
	{
		temp++;
		return 0;
	}
	
	cal_arrage(n+1,x);
	cal_arrage(n+3,x);
	cal_arrage(n+4,x);
}

main()
{
	int arr[30];
	for(int i=1;i<30;i++)
	{
		cal_arrage(0,i);
		cout<<i<<" -> "<<temp<<endl;
		arr[i]=temp;
		temp=0;
	}
}
