#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
void reverse(const char * const sPtr)
{
	if(sPtr[0]=='\0')
	{
		return;
	}
	else
	{
		reverse(&sPtr[1]);
		putchar(sPtr[0]);
	}
}
main()
{
		char c[20];
		cin>>c;
		reverse(c);
}
