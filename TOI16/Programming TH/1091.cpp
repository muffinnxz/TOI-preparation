#include<bits/stdc++.h>
using namespace std;

int n;
int weight[300005];
vector<vector<int> > vect(300005);

void init()
{
	for(int i=0;i<300005;i++)
		weight[i] = 1;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	
	int u,v;
	for(int i=0;i<n-1;i++)
	{
		cin>>u>>v;
		if(u < v) vect[u].push_back(v);
		else vect[v].push_back(u);
	}
	
	init();
	
	for(int i=1;i<n;i++)
		for(auto x : vect[i])
			if(weight[x] < weight[i] + 1) weight[x] = weight[i] + 1;
	
	cout<<*max_element(weight,weight+n+1);
}
