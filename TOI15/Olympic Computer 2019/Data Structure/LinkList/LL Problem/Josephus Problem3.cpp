#include<iostream>
using namespace std;
struct NODE
{
	int info;
	struct NODE *next;
};
typedef struct NODE sN;

sN *newNode(int a)
{
	sN *temp=new NODE;
	temp->next=temp;
	temp->info=a;
}

void sol(int n,int m)
{
	sN *head=newNode(1);
	sN *cr=head;
	for(int i=2;i<=n;i++)
	{
		cr->next=newNode(i);
		cr=cr->next;	
	}	
		cr->next=head;
	
	sN *p1=head , *p2=head;
	while(p1->next!=p1)
	{
		int count = 1; 
        while (count != m) 
        { 
            p2 = p1; 
            p1 = p1->next; 
            count++; 
        }
		p2->next = p1->next; 
        p1 = p2->next;  
	}
	printf ("Last person left standing "
            "(Josephus Position) is %d\n ", 
            p1->info); 
}

main()
{
  int n,k;
  cin>>n;
  cin>>k;
  sol(n,k);
}
