#include<bits/stdc++.h>
#define endll "\n"
using namespace std;

					// 2 3 5 7
int pftable[11][4] = {{0,0,0,0},
				   	  {0,0,0,0},
				      {1,0,0,0},
				      {0,1,0,0},
				      {2,0,0,0},
				      {0,0,1,0},
				      {1,1,0,0},
				      {0,0,0,1},
				      {3,0,0,0},
				      {0,2,0,0},
				      {1,0,1,0}};

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long int m, n;
	cin >> m >> n;
	
	vector<pair<long long int, long long int> > v;
	
	long long int x, s, t;
	for(long long int i=0;i<m;i++)
	{
		cin >> x >> s >> t;
		v.push_back(make_pair(s, -x));
		v.push_back(make_pair(t+1, x));
	}
	
	sort(v.begin(), v.end());
	
	vector<pair<long long int,long long int> > f;
	long long int mx = 1, value = 1, i = 0, pfnow[4] = {1,1,1,1};
	f.push_back(make_pair(1, -1));
	while(i < 2*m)
	{
		long long int np = v[i].first;
		while(v[i].first == np)
		{
			if(v[i].second < 0) 
			{
				for(long long int j=0;j<4;j++)
					pfnow[j] += pftable[abs(v[i].second)][j];
				// value *= abs(v[i].second);
			}
			else
			{
				for(long long int j=0;j<4;j++)
					pfnow[j] -= pftable[abs(v[i].second)][j];
				// value /= abs(v[i].second);
			}
			i++;
		}
		f.push_back(make_pair(pfnow[0] * pfnow[1] * pfnow[2] * pfnow[3], np));
		mx = max(mx, f.back().first);
	}
	f.push_back(make_pair(1, n));
	
	long long int ans = 0, len = f.size() - 1;
	for(long long int i=1;i<len;i++)
		if(f[i].first == mx) ans += f[i+1].second - f[i].second;
	cout<<mx<<" "<<ans;
}
