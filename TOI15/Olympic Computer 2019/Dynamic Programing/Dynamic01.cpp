#include<iostream>
using namespace std;

int memf[80];
unsigned long long int fib(int n)
{
	unsigned long long int temp;
	if (memf[n]!=0) return memf[n];
	else 
	{
		if(n==0||n==1) temp=1;
		else temp=fib(n-1)+fib(n-2);
		memf[n]=temp;
		return temp;
	}
}
main()
{
	int i,a;
	cin>>a;
	for(i=0;i<a;i++)
	 cout<<i<<" "<<fib(i)<<endl;
}
