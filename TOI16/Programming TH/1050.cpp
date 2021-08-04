#include<bits/stdc++.h>
#include<list>
using namespace std;

bool sortVec(vector<int> a,vector<int> b)
{
	int s = a.size() - 1;
	for(int i=0;i<s;i++)
	{
		if(a[i] == b[i]) continue;
		return a[i] < b[i];
	}
	return false;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,p;
	cin>>n>>p;
	
	vector<vector<int> > item(n,vector<int> (p+1,0));
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<p;j++)
			cin>>item[i][j];
		item[i][p] = i;
	}		
			
	sort(item.begin(),item.end(),sortVec);
	
	int lastPos[n];
	for(int i=0;i<n;i++)
	{
		lastPos[i] = item[i][p];
		item[i].erase(item[i].end() - 1);
	}
		
	vector<int> req(p);
	for(int i=0;i<p;i++)
		cin>>req[i];
	
	bool ANS = false;
	
	if(binary_search(item.begin(),item.end(),req))
	{
		ANS = true;
		cout<<lastPos[upper_bound(item.begin(),item.end(),req) - item.begin() - 1] + 1;
	}
	
	vector<int> tmp(p);
	if(!ANS)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<p;j++)
				tmp[j] = req[j] - item[i][j];
			if(binary_search(item.begin() + i,item.end(),tmp))
			{
				int a =lastPos[i] + 1,b =lastPos[upper_bound(item.begin() + i,item.end(),tmp) - item.begin() - 1] + 1;
				if(a < b) cout<<a<<" "<<b;
				else if(a > b)cout<<b<<" "<<a;
				else cout<<"NO";
				ANS = true;
				break;
			}
			if(ANS) break;
		}
	}
	
	if(!ANS) cout<<"NO";
}
