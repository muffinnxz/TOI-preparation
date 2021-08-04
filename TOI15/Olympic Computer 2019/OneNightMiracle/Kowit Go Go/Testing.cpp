#include<iostream>
#include<math.h>
using namespace std;

void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void printarr(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
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
			if(arr[j]<=arr[min]) min=j;
		swap(&arr[i],&arr[min]);
	}
}

int ls(int arr[],int x,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[i]>x) return 0;
		else if(arr[i]==x) return 1;
	}
	return 0;
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

int bis(int arr[],int x,int l,int r)
{
	if(l==r) return arr[l]==x;
	int m=l+(r-l)/2;
	if(arr[m]==x) return 1;
	else if(arr[m]>x) return bis(arr,x,l,m-1);
	else return bis(arr,x,m+1,r);
}

int rbis(int arr[],int x,int n)
{
	if(n==0) return 0;
	else return bis(arr,x,0,n-1);
}

void allpos(int x,int n)
{
	int i,v;
	for(i=0;i<n;i++)
	{
		v=(x&(1<<i))!=0;
		if(v==1) cout<<"1 ";
		else cout<<"0 ";
	}
	cout<<endl;
}
int memf[50]={0};

int fibo(int n)
{
	if(memf[n]!=0) return memf[n];
	else if(n==1||n==0) return 1;
	else 
	{
		memf[n]=fibo(n-1)+fibo(n-2);
		return fibo(n-1)+fibo(n-2);
	}
}

main()
{
	int arr[]={3,2,5,6,7,9,8,1,4};
	//int n=sizeof(arr)/sizeof(arr[0]);
	int n=2;
	int i;
	int alln=pow(2,2);
	for(i=0;i<alln;i++)
		allpos(i,n);

}
