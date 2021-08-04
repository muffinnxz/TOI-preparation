#include<bits/stdc++.h>
using namespace std;

int n;

vector<pair<int,int> > domino;
vector<pair<int,int> > dp;

int fallDomino(int p,int d)
{	
	if(d == -1 && dp[p].first != 0) return dp[p].first;
	if(d == 1 && dp[p].second != 0) return dp[p].second;
	
	if(d == -1)
	{
		int i = 1;
		while(domino[p].first - domino[p].second < domino[p-i].first)
		{ 
			if(domino[p - i].first - domino[p - i].second < domino[p].first - domino[p].second)
			{
				dp[p].first = i + fallDomino(p - i,-1);
				return dp[p].first;
			}
			i++;
			if(p-i < 0) break;
		}
		dp[p].first = i;
		return dp[p].first;
	}
	
	int i = 1;
	while(domino[p].first + domino[p].second > domino[p+i].first)
	{
		if(domino[p + i].first + domino[p + i].second > domino[p].first + domino[p].second)
		{
			dp[p].second = i + fallDomino(p + i,1);
			return dp[p].second;
		}
		i++;
		if(p+i >= n) break;
	}
	dp[p].second = i;
	return dp[p].second;
}

main()
{
	cin>>n;
	
	pair<int,int> tmp;
	for(int i=0;i<n;i++)
	{
		cin>>tmp.first>>tmp.second;
		domino.push_back(tmp);
	}
	
	tmp.first = 0;
	tmp.second = 0;
	for(int i=0;i<n;i++)
		dp.push_back(tmp);

	dp[0].first = 1;
	dp[n-1].second = 1;
	
	int maxFall = 0;
	int pos = 0;
	pair<int,char> ans;
	
	for(int i=0;i<n;i++)
	{
		if(fallDomino(i,-1) > maxFall)
		{
			maxFall = fallDomino(i,-1);
			ans.first = i + 1;
			ans.second = 'L';
		} 
		if(fallDomino(i,1) > maxFall)
		{
			maxFall = fallDomino(i,1);
			ans.first = i + 1;
			ans.second = 'R';
		} 
	}
	
	cout<<ans.first<<" "<<ans.second;
}
