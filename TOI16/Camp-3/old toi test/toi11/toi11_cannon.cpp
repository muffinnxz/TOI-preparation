#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b)
{
	if(a.first != b.first) return a.first < b.first;
	return a.second < b.second;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m, k, l;
	cin >> n >> m >> k >> l;
	
	int cannon[n];
	for(int i=0;i<n;i++)
		cin >> cannon[i];
		
	for(int i=0;i<k;i++)
	{
		int tmp, sum = 0;
		vector<pair<int,char> > v;
		for(int j=0;j<m;j++)
		{
			cin >> tmp;
			v.push_back(make_pair(tmp-l, 0));
			v.push_back(make_pair(tmp+l, 1));
		}
		sort(v.begin(), v.end(), cmp);
		
		stack<int> s;
		for(int j=0;j<v.size();j++)
		{
			if(v[j].second == 0) s.push(j);
			else
			{
				tmp = s.top();
				s.pop();
				if(s.empty()) sum += distance(lower_bound(cannon, cannon+n, v[tmp].first), 
												upper_bound(cannon, cannon+n, v[j].first));
			}	
		}
		
		cout << sum << "\n";
	}
}
