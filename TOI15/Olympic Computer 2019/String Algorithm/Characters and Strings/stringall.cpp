#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<ctype.h>

using namespace std;

main()
{
	char txt[100];
	char *pch;
	
	/*pch = strtok(txt," ");
	
	while(pch!=NULL)
	{
		cout<<pch<<endl;
		pch	= strtok(NULL,";,");
	}	
	puts(txt);*/
	
	char ch[100],tmp[2];
	gets(ch);
	int n,j,i;
	n = strlen(ch);
	for(i=0;i<n;i++)
	{
		tmp[0]=ch[i];
		tmp[1]='\0';
		j=atoi(tmp);
		cout<<j*10;
	}
}
