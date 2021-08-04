#include<iostream>
using namespace std;

int lsearch(int arr[],int n,int x)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[i]==x) return 1;
		if(arr[i]>x) return 0;
	}
	return 0;
}

int bisearch(int arr[],int x,int low,int high)
{
	if(low==high) return arr[low]==x;
	int mid=(low+high)/2;
	if(arr[mid]==x)
		return 1;
	else if(arr[mid]>x)
		return bisearch(arr,x,low,mid-1);
	else
		return bisearch(arr,x,mid+1,high);
}

int rbis(int arr[],int x,int n)
{
	if(n==0) return 0;
	else return bisearch(arr,x,0,n-1);
}
main()
{
	int arr[]={1,2,3,4,5,6,7,8,9};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	int x;
	cin>>x;
	
	cout<<rbis(arr,x,n);

}
