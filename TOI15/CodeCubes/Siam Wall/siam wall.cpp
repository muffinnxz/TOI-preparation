#include<iostream>
using namespace std;

int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int allcm(int arr[],int n)
{
	int i;
	int ans=arr[0];
	for(i=1;i<n;i++)
		ans=((arr[i] * ans)/(gcd(arr[i],ans)));
	return ans;
}
long long allgcd(int arr[],int n)
{
	long long i;
	int ans=arr[0];
	for(i=1;i<n;i++)
		ans=gcd(arr[i],ans);
	return ans;
}
main()
{
	int n,i;
	long long sum=0;
	cin>>n;
	int h[n];
	for(i=0;i<n;i++)
	{
		cin>>h[i];
		sum+=h[i];
	}
		
	long long temp=allgcd(h,n);
	cout<<sum/temp;
}
