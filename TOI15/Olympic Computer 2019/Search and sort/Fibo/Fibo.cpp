#include<iostream>
using namespace std;

int rfibo[50];

int fibo(int n)
{
	if(rfibo[n]!=0) return rfibo[n];
	if(n<=1) return 1;
	else return rfibo[n]=fibo(n-1)+fibo(n-2);
}

main()
{
	int i,n;
	cin>>n;
	for(i=0;i<50;i++)
		rfibo[0];
	for(i=0;i<n;i++)
		cout<<fibo(i)<<endl;
}
