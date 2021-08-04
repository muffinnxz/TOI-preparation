#include<stdio.h>
#include<ctype.h>
#include<iostream>
main()
{
	char a='a';
	scanf("%c",&a);
	printf("%s",isalpha(a)?"ENG.\n":"NOT ENG.");
	if(isalpha(a)) 
		printf("%c",toupper(a));
}
