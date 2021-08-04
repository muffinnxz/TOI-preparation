#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct point{
	int dis;
	int cup;
};

bool compare_dis(point a,point b)
{
	return a.dis<b.dis;
}

int calculate(int N,int M,int L,int K,point water[])
{
	int i,j;

	sort(water,water+K,compare_dis);
	
	int leastcup=water[0].cup;
	for(i=0;i<K;i++)
		if(water[i].cup<leastcup) leastcup=water[i].cup;
	
	int r=M/L,lastr=M%L;
	int cpr=leastcup/N;
	int bestplayer=0;
	
	if(r<=cpr)
	{
		bestplayer+=K*r;
		for(j=0;j<K;j++)
			water[i].cup-=K*r;	
	}
	else
	{
		r-=cpr;
		bestplayer+=(cpr*K);
		for(i=0;i<K;i++)
			water[i].cup-=cpr*N;
		for(i=0;i<r;i++)
			for(j=0;j<K;j++)
				if(water[j].cup<=0) continue;
				else
				{
					bestplayer++;
					water[j].cup-=N;
				} 	
	}
	for(i=0;i<K;i++)
	{
		if(water[i].dis<=lastr&&water[i].cup>0) bestplayer++;
		else if(water[i].dis>lastr) break;
	}
	return bestplayer;
}

int main()
{
	int n;
	cin>>n;
	
	int i,j;
	int arr[n][4];
	int ans[n];
	for(i=0;i<n;i++)
	{
		cin>>arr[i][0]>>arr[i][1]>>arr[i][2]>>arr[i][3];
		point water[arr[i][3]];
		for(j=0;j<arr[i][3];j++)
			cin>>water[j].dis>>water[j].cup;
		ans[i]=calculate(arr[i][0],arr[i][1],arr[i][2],arr[i][3],water);
	}
		
	for(i=0;i<n;i++)
		cout<<ans[i]<<endl;	
	return 0;
}
