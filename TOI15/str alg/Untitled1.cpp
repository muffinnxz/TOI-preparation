#include<string.h>
#include<iostream>
#include<list>
using namespace std;

main()
{
	int n;
	cin>>n;
	char c[n][1000];
	int i;
	for(i=0;i<n;i++)
		cin>>c[i];
	char check[1000];
	cin>>check;	
	for(i=0;i<n;i++)
	{
		if(strcmp(c[i],check)==0)
		{
			cout<<i+1;
			break;
		} 
	}
}
