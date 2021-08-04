#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<list>
#include<stack>
#include<queue>
using namespace std;

typedef struct datalist
{
	int cmd,val;
}datalist;

main()
{
	int n,i,s=1,q=1,pr=1;
	
	cin>>n;
	datalist cmd[n];
	
	priority_queue<int> Datapriqueue;
	queue<int> Dataqueue;
	stack<int> Datastack;
	
	for(i=0;i<n;i++)
	{
		cin>>cmd[i].cmd;
		cin>>cmd[i].val;
	}
	
	for(i=0;i<n;i++)
	{
		
		if(cmd[i].cmd==1) 
		{
			Datastack.push(cmd[i].val);
			Dataqueue.push(cmd[i].val);
			Datapriqueue.push(cmd[i].val);
		}
		
		else if(cmd[i].cmd==2)
		{
			if(cmd[i].val==Datastack.top()&&s!=0) 
			{
				Datastack.pop();
				s=1;
			}
			else s=0;
			
			if(cmd[i].val==Dataqueue.front()&&q!=0)
			{
				Dataqueue.pop();
				q=1;
			}
			else q=0;
			
			if(cmd[i].val==Datapriqueue.top()&&pr!=0)
			{
				Datapriqueue.pop();
				pr=1;
			}
			else pr=0;
		}
	}
	if(s==1&&q==0&&pr==0) cout<<"Stack";
	else if(s==0&&q==1&&pr==0) cout<<"Queue";
	else if(s==0&&q==0&&pr==1) cout<<"Priority Queue";
	else if(s==0&&q==0&&pr==0) cout<<"Impossible";
	else cout<<"Not Sure";
}
