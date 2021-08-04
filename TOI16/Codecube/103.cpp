#include<bits/stdc++.h>
#define endll "\n"
using namespace std;

bool cmpV(pair<int,int> a, pair<int,int> b)
{
	if(a.first != b.first) return a.first < b.first;
	return a.second > b.second;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, p;
	cin >> n >> p;
	
	vector<pair<int,int> > v;
	int a, b;
	for(int i=0;i<n;i++)
	{
		cin >> a >> b;
		v.push_back(make_pair(min(a,b), 1));
		v.push_back(make_pair(max(a,b), -1));
	}
	
	sort(v.begin(), v.end(), cmpV);
	
	a = -1, b = -1;
	int now = 0, mn = INT_MAX;
	for(int i=0;i<2*n;i++)
	{
		now += v[i].second;
		if(now == n) a = v[i].first;
		else if(now == n-1 && v[i].second == -1) b = v[i].first;
	}
	
	if(a == -1) cout << -1;
	else if(p >= a && p <= b) cout << 0;
	else cout << min(abs(p - a), abs(p - b));
}
