#include<bits/stdc++.h>
#define endll "\n"
using namespace std;
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<pair<int,int> > v;
	int a, b;
	for(int i=0;i<n;i++)
	{
		cin >> a >> b;
		v.push_back(make_pair(a, 1));
		v.push_back(make_pair(b, -1));
	}
	
	sort(v.begin(), v.end());
	
	int now = 0, mx=INT_MIN;
	for(int i=0;i<2*n;i++)
	{
		now += v[i].second;
		mx = max(mx, now);
	}
	
	cout << mx;
}
