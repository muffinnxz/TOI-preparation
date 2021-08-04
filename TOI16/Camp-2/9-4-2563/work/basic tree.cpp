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

void printlevel(NODE *root,int level)
{
	if(root == NULL) return;
	if(level == 0) cout<<root->data<<" ";
	printlevel(root->left,level-1);
	printlevel(root->right,level-1);
}

int findth(NODE *root)
{
	if(root == NULL) return -1;
	return max(1+findth(root->left),1+findth(root->left));
}

void BFS(NODE *root)
{
	int h = findth(root);
	for(int i=0;i<=h;i++)
		printlevel(root,i);
	cout<<endl;
}

bool TS(NODE *root , int x)
{
	if(root == NULL) return false;
	if(root->data == x) return true;
	return TS(root->left,x) || TS(root->right,x);
}

void BFS_queue(NODE *root)
{
	if(root == NULL) return;
	queue<NODE*> q;
	q.push(root);
	
	NODE *tmp;
	while(!q.empty())
	{
		tmp = q.front();
		q.pop();
		cout<<tmp->data<<" ";
		if(tmp->left != NULL) q.push(tmp->left);
		if(tmp->right != NULL) q.push(tmp->right); 
	}
	cout<<endl;
}

void DFSinorder(NODE *root)
{
	if(root == NULL) return;
	DFSinorder(root->left);
	cout<<root->data<<" ";
	DFSinorder(root->right);
}

void DFSpreorder(NODE *root)
{
	if(root == NULL) return;
	cout<<root->data<<" ";
	DFSpreorder(root->left);
	DFSpreorder(root->right);
}

void DFSpostorder(NODE *root)
{
	if(root == NULL) return;
	DFSpostorder(root->left);
	DFSpostorder(root->right);
	cout<<root->data<<" ";
}

void insert(NODE *root,int n)
{
	NODE *p = new node(n);

	queue<NODE*> q;
	q.push(root);
	
	NODE *tmp;
	while(!q.empty())
	{
		tmp = q.front();
		q.pop();
		if(tmp->left != NULL) q.push(tmp->left);
		else{
			tmp->left = p;
			return;
		}
		if(tmp->right != NULL) q.push(tmp->right);
		else{
			tmp->right = p;
			return;
		} 
	}
}

void delDeep(NODE *root,NODE *deep)
{
	queue<NODE*> q;
	q.push(root);
	
	NODE *tmp;
	while(!q.empty())
	{
		tmp = q.front();
		q.pop();
		
		if(tmp == deep)
		{
			tmp = NULL;
			delete(deep);
			return;
		}
		if(tmp->right == deep)
		{
			tmp->right = NULL;
			delete(deep);
			return;
		}
		else if(tmp->right != NULL) q.push(tmp->right);
		if(tmp->left == deep)
		{
			tmp->left = NULL;
			delete(deep);
			return;
		}
		else if(tmp->right != NULL) q.push(tmp->left);
	}
}

NODE* del(NODE *root,int key)
{
	if(root == NULL) return NULL;
	if(root->left == NULL && root->right == NULL)
	{
		if(root->data == key) return NULL;
		return root;
	}
	
	queue<NODE*> q;
	q.push(root);
	
	NODE *key_node = NULL;
	NODE *tmp;	
	while(!q.empty())
	{
		tmp = q.front();
		q.pop();
		
		if(tmp->data == key) key_node = tmp;
		if(tmp->left != NULL) q.push(tmp->left);
		if(tmp->right != NULL) q.push(tmp->right);
	}
	
	if(key_node != NULL)
	{
		int x = tmp->data;
		delDeep(root,tmp);
		key_node->data = x;	
	}
	
	return root;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	NODE *root = new node(1);
	insert(root,2);
	insert(root,3);
	insert(root,4);
	insert(root,5);
	insert(root,6);
	insert(root,7);
	
	BFS(root);
	root = del(root,7);
	BFS(root);
	insert(root,8);
	BFS(root);
}
