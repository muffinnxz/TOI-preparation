#include<stdio.h>
#include<iostream>
using namespace std;
class Food
{
	string name;
	int val;
	int cal;
	public:
	Food();
	Food(string,int,int);
	string getname() {return name;}
	int getval(){return val;}
	int getcal(){return cal;}
};
Food::Food()
{
	name="";
	val=0;
	cal=0;	
}
Food::Food(string s,int v,int c)
{
	name=n;
	val=v;
	cal=c;
}
main()
{
	Food *menu;
	menu=new Food[8];
}
