#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void print(int arr[])
{
	for(int i=0;i<5;i++)
		cout<<arr[i]<<" ";
	cout<<'\n';
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int arr[5];
	for(int i=0;i<5;i++)
		cin>>arr[i];
		
	for(int i=0;i<4;i++)
		for(int j=0;j<4-i;j++)
			if(arr[j] > arr[j+1])
			{
				swap(&arr[j],&arr[j+1]);
				print(arr);	
			}
}
