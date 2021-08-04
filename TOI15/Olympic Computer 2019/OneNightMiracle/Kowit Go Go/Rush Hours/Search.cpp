#include<iostream>
#include<string.h>
using namespace std;

int lsearch(char *str,int n,char x)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(str[i]>x) return 0;
		if(str[i]==x) return 1;
	}
	return 0;
}

void swap(char *a,char *b)
{
	char temp=*a;
	*a=*b;
	*b=temp;
}

void bsort(char *str,int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(str[j]>str[j+1]) swap(&str[j],&str[j+1]);
}

int bisearch(char *str,char x,int l,int r)
{
	if(l==r) return str[l]==x;
	int mid=(l+r)/2;
	if(str[mid]==x) return 1;
	else if(str[mid]>x) return bisearch(str,x,l,mid-1);
	else return bisearch(str,x,mid+1,r);
}
int ribs(char *str,char x,int n)
{
	if(n==0) return 0;
	else return bisearch(str,x,0,n-1);
}
main()
{
	char str[]="Sriyapai School";
	int n=strlen(str);
	
	bsort(str,n);
	
	char x;
	cin>>x;
	
	cout<<ribs(str,x,n);
	
}
