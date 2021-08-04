#include<iostream>
using namespace std;
struct NODE
{
	int data;
	struct NODE *next;
};

NODE *newNode(int data)
{
	NODE *temp=new NODE;
	temp->next=temp;
	temp->data=data;
}

void calculate(int n,int m)
{
	NODE *head=newNode(1);
	NODE *ptr1=head;
	for(int i=2;i<=n;i++)
	{
		ptr1->next=newNode(i);
		ptr1=ptr1->next;		
	}
		ptr1->next=head;
		
	NODE *a=head,*b=head;
	while(a->next!=a)
	{
		int c=1;
		while(c!=m)
		{
			b=a;
			a=a->next;
			c++;
		}
		b->next=a->next;
		a=b->next;
	}
	cout<<"ANS is "<<a->data;
}
main()
{
	int n,m;
	cout<<"Enter n : ";
	cin>>n;
	cout<<"Enter m : ";
	cin>>m;
	calculate(n,m);
	
}
