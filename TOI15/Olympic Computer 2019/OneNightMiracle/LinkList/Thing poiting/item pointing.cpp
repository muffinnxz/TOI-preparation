#include<stdio.h>
#include<iostream>
#include<list>
using namespace std;

main()
{
	int item,player;
	cin>>item;
	cin>>player;
	char cmd[player];
	int n[player];
	int i,j;
	list<int> itemlist;
	list<int>::iterator it,itb;
	
	for(i=1;i<=item;i++)
		itemlist.push_back(i);
		
	for(i=0;i<player;i++)
	{
		cin>>cmd[i];
		cin>>n[i];	
	}

	int c=0;
	for(i=0;i<player;i++)
	{
		if(i==0) 
		{
			it=itemlist.begin();
			itb=it;
			c++;
		}
		if(cmd[i]=='F')
		{
			it=itemlist.begin();
			for(j=0;j<n[i]-1;j++)
				it++;
			cout<<*it<<" ";
			c++;
		}
		else if(cmd[i]=='L')
		{
			for(j=0;j<n[i];j++)
				it--;
			cout<<*it<<" ";
			c++;
		}
		else if(cmd[i]=='R')
		{
			for(j=0;j<n[i];j++)
				it++;
			cout<<*it<<" ";
			c++;
		}
		else if(cmd[i]=='S')
		{
			cout<<*it<<" ";
			c++;
		}
		else 
		{
			cout<<*itb<<" ";
			it=itb;
			c++;
		}
		if(c==2)
		{
			itb=it;
			c=0;
		}
	}
}
