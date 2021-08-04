#include<iostream>
using namespace std;
main()
{
	int arr[]={31,10,22,31,48,51,69,74,87,99,101,110,82,93,44,150,156,77,210,79,200,28,26,27,14,65,206,270,270,290,300,310};
	int n,child,count=1;
	int *pint;
	cin>>n;
	pint=&arr[1];
	while(*pint!=n)
	{
		pint++;
		count++;
	}
	child=2*count;
	cout<<"Index of "<<*pint<<" is "<<count<<endl;
	cout<<"Child Left is "<<arr[child]<<endl;
	cout<<"Child Right is "<<arr[child+1]<<endl;
	cout<<"Sum is "<<arr[child]+arr[child+1]<<endl;
}
