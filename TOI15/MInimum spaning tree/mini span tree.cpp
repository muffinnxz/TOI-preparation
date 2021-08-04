#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct path{
	int u;
	int v;
	int w;
}NODE;

int comw(const void *a,const void *b)
{
	NODE *patha=(NODE*)a;
	NODE *pathb=(NODE*)b;
	return(patha->w - pathb->w);
}

int checkcycle(int track[],int s)
{
	int temp=s;
	s=track[s];
	while(s!=-1&&s!=temp)
		s=track[s];
	if(s==-1) return 0;
	else return 1;
}

main()
{
	int n,m;
	cin>>n>>m;
	int i,j;
	NODE path[m];
	int track[m];
	for(i=0;i<m;i++)
	{
		cin>>path[i].u>>path[i].v>>path[i].w;
		path[i].u--;
		path[i].v--;
	}
	qsort(path,m,sizeof(NODE),comw);
	for(i=0;i<m;i++)
		cout<<path[i].u<<" "<<path[i].v<<" "<<path[i].w<<endl;;
	for(i=0;i<m;i++)
		track[i]=-1;
	int sum=0;
	sum+=path[0].w;
	track[path[0].v]=path[0].u;
	for(i=1;i<m;i++)
	{
		track[path[i].v]=path[i].u;
		if(checkcycle(track,path[i].v)) 
		{
			track[path[i].v]=-1;
			continue;
		}
		else cout<<i<<" ";
	}
	cout<<sum;
			
}
