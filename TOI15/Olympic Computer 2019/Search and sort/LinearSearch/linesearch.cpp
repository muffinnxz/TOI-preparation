#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<string>
using namespace std;

int lsearch(char *s,char x)
{
	int i;
	for(i=0;i<strlen(s);i++)
	{
		if(x==s[i]) return 1;
		if(x<s[i]) return 0;
	}
	return 0;
}

int bisearch(char *s,char x)
{
	int i,n=strlen(s),half;
	if(n==0) 
		return 0;
	else if (n==1) 
		return s[0]==x; 
	else
	{
		half=n/2;
		if(s[half]>x)
		{
			s[half]='\0';
			return bisearch(s,x);
		}
		else return bisearch(s+half,x);
	}
}


int bisearch3(char *s,char x,int low,int high)
{
	if(low==high) return s[low]==x;
	int mid=(low+high)/2;
	if(s[mid]==x)
		return 1;
	else if(s[mid]>x)
	{
		if(low==mid)
			return 0;
		else
			return bisearch3(s,x,low,mid-1);
	}
}

int rbis(char *s,char x)
{
	int n=strlen(s);
	if(n==0)
		return 0;
	else
		return bisearch3(s,x,0,n-1);
}

main()
{
	char s[]="abcfgjklmnopruvwxy";
	char x;
	cin>>x;
	cout<<rbis(s,x);
}
