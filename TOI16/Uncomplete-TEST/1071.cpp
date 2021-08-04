#include<bits/stdc++.h>
using namespace std;

bool cmpPaper(pair<int,int> a,pair<int,int> b)
{
	return sqrt(a.first * a.first + a.second * a.second) < sqrt(b.first * b.first + b.second * b.second);
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	list<pair<int,int> > paper;
	int x,y,r;
	for(int i=0;i<n;i++)
	{
		cin>>x>>y;
		paper.push_back(make_pair(x,y));
	}
	
	paper.sort(cmpPaper);
	
	int bomb;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y>>r;
		
		if(paper.empty()) cout<<"0\n";
		else
		{
			bomb = 0;
			
			for(auto it1 = paper.begin();it1 != paper.end(); it1++)
			{
				if(it1->first > x+r && it1->second > y+r);
				if(it1->first >= x-r && it1->first <= x+r && it1->second >= y-r && it1->second <= y+r)
				{
					auto it2 = it1;
					it1++;
					paper.erase(it2);
					it1--;
					bomb++;
				}
			}
		
			cout<<bomb<<"\n";	
		}
	}
}
