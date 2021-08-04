using namespace std;
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string>
#include<list>
#include<stack>
main()
{
	char n[1000];
	gets(n);
	int a=0,b=0;
	char *ptrch=&n[0];
	while(*ptrch=='('||*ptrch==')')
	{
		if(*ptrch=='(') a++; 
		if(*ptrch==')') b++;
		ptrch++;
	}
	if(a==b) cout<<"0";
	else if(a>b) cout<<a-b;
	else cout<<b-a;

}
