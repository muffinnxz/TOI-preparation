#include<iostream>
using namespace std;
	struct NODE
	{
		int info;
		struct NODE *next;
	};
		typedef struct NODE snd;
		typedef struct NODE *P;
main()
{
	P head,newp,cr,pr,rm;
	newp=new NODE;
	newp->info=1; newp->next=NULL;
	head=newp; pr=newp;
	
	newp=new NODE;
	newp->info=2; newp->next=NULL;
	pr->next=newp; pr=newp;
	
	newp=new NODE;
	newp->info=3; newp->next=NULL;
	pr->next=newp; pr=newp;
	
	cr=head;
		while(cr!=NULL)
		{
			cout<<"->"<<cr->info;
			rm=cr;
			cr=cr->next;
			delete(rm);
			cout<<'\n';
		}
//	snd *p;
//	p=&nd1;
//	nd1.info=1; nd1.next=&nd2;
//	nd2.info=2; nd2.next=&nd3;
//	nd3.info=3; nd3.next=NULL;
//	while (p!=NULL)
//		{
//			cout<<p->info<<"->";
//			p=p->next;
//		}
//		cout<<endl;
}
