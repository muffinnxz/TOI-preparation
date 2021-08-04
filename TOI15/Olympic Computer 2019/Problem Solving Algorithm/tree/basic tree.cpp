#include<iostream>
using namespace std;

void ptree(node *a);
{
	if(a->left||a->right==)
}
struct node
{
	int data;
	struct node *left;
	struct node *right;	
};

	typedef struct node node;
	
node *newnode(int data)
{
	node *temp=new node;
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
}

main()
{
	node *p=newnode(1);
	node *run=p;
	p->left=newnode(2);
	p->right=newnode(3);
	
	p->left->left=newnode(4);
	
	printf("%d -> %d,%d",p->data,p->left->data,p->right->data);
}
