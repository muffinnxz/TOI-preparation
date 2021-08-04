#include<iostream>
#include<list>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

typedef struct card
{
	int face;
	int suit;
}card;
int facet(char a)
{
	switch(a)
	{
	case '3':return 3;break;
	case '4':return 4;break;
	case '5':return 5;break;
	case '6':return 6;break;
	case '7':return 7;break;
	case '8':return 8;break;
	case '9':return 9;break;
	case 'T':return 10;break;
	case 'J':return 11;break;
	case 'Q':return 12;break;
	case 'K':return 13;break;
	case 'A':return 14;break;
	case '2':return 15;break;
	}
}
int suitt(char a)
{
	switch(a)
	{
	case 'C':return 1;break;
	case 'D':return 2;break;
	case 'H':return 3;break;
	case 'S':return 4;break;
	}
}
int compareface (const void *a,const void *b)
{
	card *cardA=(card*)a;
	card *cardB=(card*)b;
	return (cardB->face - cardA->face);
}
int comparesuit (const void *a,const void *b)
{
	card *cardA=(card*)a;
	card *cardB=(card*)b;
	return (cardB->suit - cardA->suit);
}
main()
{
	int n,i,ptt;
	cin>>n;
	card hand[n],handr[n];
	card *p,*s;
	for(i=0;i<n;i++)
	{
		char face,suit;
		cin>>face;
		hand[i].face=facet(face);
		cin>>suit;
		hand[i].suit=suitt(suit);
	}
	qsort(hand,n,sizeof(card),compareface);
	for(i=0;i<n;i++)
	{
		handr[i].face=hand[n-i-1].face;
		handr[i].suit=hand[n-i-1].suit;
	}
	
	s=&handr[0];
	p=s;
	int j=0;
	
	for(int x=0;x<13;x++)
	{
		int c=0;
		while(p->face==s->face)
		{
			p++;
			c++;
		}
		card handc[c],handcr[c];
		p=s;
		
		int z=0;
		for(z=0;z<c;z++)
		{
			handc[z].face=p->face;
			handc[z].suit=p->suit;
			p++;
		}
		qsort(handc,c,sizeof(card),comparesuit);
		for(i=0;i<c;i++)
			handcr[i]=handc[c-i-1];
			
		int a=0;
		while(s->face!=p->face)
		{
			handr[j]=handcr[a];
			s++;
			j++;
			a++;
		}
	}
	cout<<endl;
	for(i=0;i<n;i++)
		cout<<handr[i].face<<" "<<handr[i].suit<<endl;
}
