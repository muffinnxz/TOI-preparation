#include<iostream>
using namespace std;

int memfibo[50];

int fibo(int n)
{
	if(memfibo[n]!=0) return memfibo[n];
	if(n==1||n==0) return 1;
	else 
	{
		memfibo[n]=fibo(n-1)+fibo(n-2);		
		return fibo(n-1)+fibo(n-2);
	}
}

main()
{
	int i,n;
	cin>>n;
	for(i=0;i<50;i++)
		memfibo[i]=0;
	for(i=0;i<n;i++)
		cout<<fibo(i)<<endl;
}
