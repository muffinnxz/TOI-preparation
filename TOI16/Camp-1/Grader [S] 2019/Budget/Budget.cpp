#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

struct Promo{
	int size;
	int price;
};

bool compare_price(Promo a,Promo b)
{
	return a.price<b.price;
}

int findminp(int n,Promo Pro[],int P)
{
	for(int i=0;i<P;i++)
        if(Pro[i].size>=n) return Pro[i].price;
  return INT_MAX;
}

int minKey(vector<int> key,vector<bool> mstSET,int B)
{
	int min=INT_MAX, minPTR;
	for(int i=0;i<B;i++)
	{
		if(mstSET[i]==false&&key[i]<min)
		{
			min=key[i];
			minPTR=i;
		}
	}

	return minPTR;
}

int primMST(vector<vector<int> > road,int B)
{
	vector<int> parent(B);
	vector<int> key(B,INT_MAX);
	vector<bool> mstSET(B,false);

	key[0]=0;
	parent[0]=-1;

	for(int i=0;i<B-1;i++)
	{
		int u=minKey(key,mstSET,B);

		mstSET[u]=true;

		for(int v=0;v<B;v++)
		{
			if(road[u][v]!=-1&&mstSET[v]==false&&road[u][v]<key[v])
			{
				parent[v]=u;
				key[v]=road[u][v];
			}
		}
	}

	int sum=0;
	for(int i=1;i<B;i++)
		sum+=road[i][parent[i]];
	return sum;
}

int main()
{
	int B,E;
	cin>>B>>E;

	vector<vector<int> > road(B,vector<int> (B,-1));
	int a,b,c,d;

	for(int i=0;i<E;i++)
	{
	   scanf("%d %d %d %d",&a,&b,&c,&d);
		if(d==1)
		{
			road[a][b]=0;
			road[b][a]=0;
		}
		else
		{
			road[a][b]=c;
			road[b][a]=c;
		}
	}

	int P;
	cin>>P;
	Promo Pro[P];

	for(int i=0;i<P;i++)
     scanf("%d %d",&Pro[i].size,&Pro[i].price);
	
	sort(Pro,Pro+P,compare_price);

	for(int i=0;i<B;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(road[i][j]==0||road[i][j]==-1) continue;
			int shp=findminp(road[i][j],Pro,P);
			road[i][j]=shp;
			road[j][i]=shp;
		}
	}

	cout<<primMST(road,B);

	return 0;
}

