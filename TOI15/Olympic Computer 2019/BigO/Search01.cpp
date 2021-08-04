#include<stdio.h>
void findc(char y[],char x)
{
	char i=0;
	char *p;
	p=&y[0];
	while(*p!='\0')
	{
		if(*p==x) 
		{
			printf("Found at %d",i+1);
			break;
		}
		else
		{
			p++;
			i++;
			if(*p=='\0') 
			{
				printf("Not found");
				break;
			}
		}
	}
}
main()
{
	char x[]="abcdef";
	findc(x,'g');
}
