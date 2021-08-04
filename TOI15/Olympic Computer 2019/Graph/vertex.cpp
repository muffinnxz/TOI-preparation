using namespace std;
#include<iostream>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
void findvcon(int vertexp[7][7])
{
	int i,j;
	cout<<"\n";
	
	for(i=0;i<7;i++)
	{
		for(j=0;j<7;j++)
		{
			if(vertexp[i][j]==1) printf("(%d,%d),", j+1,i+1);
		}
	}
}

void findvin(int vertexp[7][7])
{

	int i,j;
	cout<<"\nVertex in :";
	
	for(i=0;i<7;i++)
	{
		cout<<"\n"<<i+1<<":";
		int c=0;
		for(j=0;j<7;j++)
		{
			if(vertexp[i][j]==1) c++;
		}
		cout<<c;
	}
}

void findvout(int vertexp[7][7])
{
	int i,j;
	cout<<"\nVertex out :";
	
	for(i=0;i<7;i++)
	{
		cout<<"\n"<<i+1<<":";
		int c=0;
		for(j=0;j<7;j++)
		{
			if(vertexp[j][i]==1) c++;
		}
		cout<<c;
	}
}

main()
{
	int vertex[7]={1,2,3,4,5,6,7};
	
	int vertexp[7][7]={{0,0,0,0,1,0,0}
					  ,{1,0,0,0,0,0,0}
					  ,{0,0,0,1,0,0,1}
					  ,{0,0,0,0,1,1,0}
				      ,{0,1,0,0,0,0,0}
					  ,{0,0,1,1,0,0,0}
					  ,{0,0,0,0,0,0,0}};
	findvcon(vertexp);
	findvin(vertexp);
	findvout(vertexp);
		cout<<endl;
	char s[10];
	char *pch;
	char sk[2];
	char sn[2];
	
	cout<<"Enter Command : ";
	gets(s);
	
	pch = strtok(s,":");
	pch	= strtok(NULL,":");
	
	int i=0;
	while(pch!=NULL)
	{
		sk[i]=*pch;
		pch	= strtok(NULL,":");
		i++;
	}	
		sn[0]=sk[0];
		sn[1]='\0';

	if(sk[1]=='i')
	{
		int i;
		int c=0;
		for(i=0;i<7;i++)
			if(vertexp[atoi(sn)-1][i]==1) c++;
		cout<<sn<<" in = "<<c;
	}
	else
	{
		int i;
		int c=0;
		for(i=0;i<7;i++)
			if(vertexp[i][atoi(sn)-1]==1) c++;
		cout<<sn<<" out = "<<c;
	}
}
