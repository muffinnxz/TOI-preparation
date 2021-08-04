#include<iostream>
#include<string.h>
using namespace std;

int stoint(char a[1000],b[1000])
{
	int ai,bi;
	if(a=="ONE") ai==1;
	else if(a=="TWO") ai==2;
	else if(a=="THREE") ai==3;
	else if(a=="FOUR") ai==4;
	else if(a=="FIVE") ai==5;
	else if(a=="SIX") ai==6;
	else if(a=="SEVEN") ai==7;
	else if(a=="EIGHT") ai==8;
	else if(a=="NINE") ai==9;
	
	if(a=="ELEVEN") ai==11;
	else if(a=="TWEVLE") ai==12;
	else if(a=="THIR") ai==3;
	else if(a=="FOU") ai==4;
	else if(a=="FIF") ai==5;
	else if(a=="SIX") ai==6;
	else if(a=="SEVEN") ai==7;
	else if(a=="EIGHT") ai==8;
	else if(a=="NINE") ai==9;
}
main()
{
	char enter[1000];
	char *pch;
	pch=strtok(enter," ");
	char a[1000],b[1000];
	int i=0;
	while(pch!=NULL)
	{
		if(i=0)
			a=pch;
		else if(i=1)
			b=pch;
		else
		{
			i=0;
		}
		
	}
}
