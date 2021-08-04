#include<iostream>
#include<string.h>
using namespace std;

void merge(char *str,int l,int m,int r)
{
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	char L[n1],R[n2];
	
	for(i=0;i<n1;i++)
		L[i]=str[l+i];
	for(j=0;j<n2;j++)
		R[j]=str[m+1+j];
		
	i=0;
	j=0;
	k=l;
	
	while(i<n1&&j<n2)
	{
		if(L[i]<=R[j])
		{
			str[k]=L[i];
			i++;
		}
		else
		{
			str[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		str[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		str[k]=R[j];
		j++;
		k++;
	}
}

void msort(char *str,int l,int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;
		msort(str,l,m);
		msort(str,m+1,r);
		merge(str,l,m,r);
	}
}

int bis(char *str,char x,int l,int r)
{
	if(l==r) return str[l]==x;
	int m=l+(r-l)/2;
	if(str[m]==x) return 1;
	else if(str[m]>x) return bis(str,x,l,m-1);
	else return bis(str,x,m+1,r);
}

int rbis(char *str,char x,int n)
{
	if(n==0) return 0;
	else bis(str,x,0,n-1);
}

main()
{
	char str[]="sriyapai";
	int n=strlen(str);
	char x;
	msort(str,0,n-1);
	puts(str);
	cin>>x;
	cout<<rbis(str,x,n);
}
