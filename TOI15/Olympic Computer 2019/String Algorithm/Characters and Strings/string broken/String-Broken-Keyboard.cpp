#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<list>
#include<stack>
#include<queue>
#include<string.h>
using namespace std;

main()
{
	char c,*pch;
	char arr[1000];
	cin>>c;
	scanf("%s",arr);
	char temp[2];
	temp[0]=c;
	temp[1]='\0';
	pch=strtok(arr,temp);
	while(pch!=NULL)
	{
		cout<<pch<<" ";
		pch=strtok(NULL,temp);
	}
}
