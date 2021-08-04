using namespace std;
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string>
#include<list>
#include<stack>
typedef struct work
{
	char name;
	int time;
	int value;
}work;

int compareval (const void *a,const void *b)
{
	work *workA=(work*)a;
	work *workB=(work*)b;
	return (workB->value - workA->value);
}
main()
{
	int i,totaltime=0;
	work n[5],nr[5];
	for(i=0;i<5;i++)
	{
		cin>>n[i].name>>n[i].time>>n[i].value;
		totaltime+=n[i].time;
	}
	qsort(n,5,sizeof(work),compareval);
	for(i=0;i<5;i++)
		nr[i]=n[4-i];
	for(i=0;i<5;i++)
		cout<<nr[i].name<<" ";
	cout<<endl<<"Turnaround Time = "<<totaltime<<" minute.";
}
