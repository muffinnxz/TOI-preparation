#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
main()
{
	char ph[10];
	char *t;
	
	scanf("%s",ph);
	int c=0;
	for(t=&ph[0];*t!=NULL;t++)
	{
		c++;
	}
	if(c!=10) printf("Error!");
	
	
}
