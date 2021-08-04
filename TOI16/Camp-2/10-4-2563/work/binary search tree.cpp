#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left,*right;
	node(int n)
	{
		this->data = n;
		left = right = NULL; 
	}
}NODE;

void insert(NODE *root,int n)
{
	if(n < root->data)
		if(root->left == NULL) root->left = new node(n);
		else insert(root->left,n);	
	else if(n > root->data)
		if(root->right == NULL) root->right = new node(n);
		else insert(root->right,n);
}

void DFSinorder(NODE *root)
{
	if(root == NULL) return;
	DFSinorder(root->left);
	cout<<root->data<<" ";
	DFSinorder(root->right);
}

NODE *findkey(NODE *root,int key)
{
	if(root == NULL) return NULL;
	if(root->data == key) return root;
	if(key < root->data) return findkey(root->left,key);
	return findkey(root->right,key);
}

NODE *findmostleft(NODE *root)
{
	if(root->left == NULL) return root;
	return findmostleft(root->left);
}

NODE *findparent(NODE *root,NODE *key)
{
	if(root->left == key || root->right == key) return root;
	if(key->data < root->data) return findparent(root->left,key);
	return findparent(root->right,key);
}

NODE *delNode(NODE *root,int key)
{
	if(root == NULL) return NULL;
	if(root->left == NULL && root->right == NULL)
	{
		if(root->data == key)
		{
			delete(root);
			return NULL;
		} 
		return root;
	}
	
	NODE *keyNode = findkey(root,key);
	if(keyNode != NULL)
	{
		if(keyNode->left == NULL && keyNode->right == NULL)
		{
			NODE *tmp = findparent(root,keyNode);
			if(tmp->left == keyNode) tmp->left = NULL;
			else tmp->right = NULL;
			delete(keyNode);
		}
		else if(keyNode->left != NULL && keyNode->right != NULL)
		{
			NODE *mostleft = findmostleft(keyNode->right);
			NODE *tmp = findparent(keyNode,mostleft);
			int x = mostleft->data;
			if(tmp == keyNode) tmp->right = mostleft->right;
			else tmp->left = mostleft->right;
			delete(mostleft);
			keyNode->data = x;
		}
		else
		{
			NODE *tmp = findparent(root,keyNode);
			if(tmp->left == keyNode)
			{
				if(keyNode->left != NULL) tmp->left = keyNode->left;
				else tmp->left = keyNode->right;
			}
			else
			{
				if(keyNode->left != NULL) tmp->right = keyNode->left;
				else tmp->right = keyNode->right;
			}
			delete(keyNode);
		}
	}
	return root;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	NODE *root = new node(5);
	insert(root,1);
	insert(root,3);
	insert(root,2);
	insert(root,4);
	insert(root,10);
	insert(root,8);
	insert(root,6);
	insert(root,9);
	insert(root,15);
	insert(root,13);
	insert(root,11);
	insert(root,14);
	
	DFSinorder(root);
	
	root = delNode(root,5);
	
	cout<<"\n";
	DFSinorder(root);
}
