#include<iostream>
using namespace std;

void printarr(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void bsort(int arr[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
			if(arr[j]>arr[j+1]) swap(&arr[j],&arr[j+1]);
}

void ssort(int arr[],int n)
{
	int i,j,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
			if(arr[j]<arr[min]) min=j;
		swap(&arr[i],&arr[min]);	
	}	
}

void merge(int arr[],int l,int m,int r)
{
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	int L[n1],R[n2];
	
	for(i=0;i<n1;i++)
		L[i]=arr[l+i];
	for(j=0;j<n2;j++)
		R[j]=arr[m+1+j];
		
	i=0;
	j=0;
	k=l;
	
	while(i<n1&&j<n2)
	{
		if(L[i]<=R[j])
		{
			arr[k]=L[i];
			i++;
		}
		else	
		{
			arr[k]=R[j];
			j++;
		}
		k++;
	}	
	
	while(i<n1)
	{
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=R[j];
		j++;
		k++;
	}
}

void msort(int arr[],int l,int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;
		msort(arr,l,m);
		msort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}
main()
{
	int arr[]={7,5,3,1,9,6,4,8,2};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	msort(arr,0,n-1);
	
	printarr(arr,n);
}
