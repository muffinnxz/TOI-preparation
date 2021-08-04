#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

typedef struct Food
{
	char name[50];
	int val,cal;
}Food;
Food menu[8]={{"wine",89,123},
			  {"beer",90,154},
			  {"pizza",30,258},
			  {"burger",50,354},
			  {"fries",90,365},
			  {"coke",79,150},
			  {"apple",90,95},
			  {"donut",10,195},};

int compareval (const void *a,const void *b)
{
	Food *foodA=(Food*)a;
	Food *foodB=(Food*)b;
	return (foodB->val - foodA->val);
}

int comparecal (const void *a,const void *b)
{
	Food *foodA=(Food*)a;
	Food *foodB=(Food*)b;
	return (foodB->cal - foodA->cal);
}

void greedy(int maxcost)
{
	int i,value=0,calories=0;
	for(i=0;i<8;i++)
	{
		if(calories<=maxcost&&calories+menu[i].cal<=maxcost)
		{
			printf("%s ",menu[i].name);
			calories+=menu[i].cal;
			value+=menu[i].val;
		}
	}
}

main()
{

	int i;
	qsort(menu,8,sizeof(Food),comparecal);
	for(i=0;i<8;i++)
	{
		cout<<menu[i].name<<" "<<menu[i].val<<" "<<menu[i].cal<<"\n";
	}
	greedy(750);
}
