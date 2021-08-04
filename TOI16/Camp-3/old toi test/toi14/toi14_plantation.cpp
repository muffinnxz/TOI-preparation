#include<bits/stdc++.h>
#define pii pair<int,int>
#define INF 1e9
using namespace std;

bool cmp(pii A, pii B)
{
	if(A.second != B.second) return A.second < B.second;
	return A.first < B.first;
}

void solve()
{
	int N, R, D;
	cin >> N >> R >> D;
	
	pii point[N];
	for(int i=0;i<N;i++)
		cin >> point[i].first >> point[i].second;
	sort(point, point + N);
	
	set<pii, decltype(cmp)*> s(cmp);
	
	double min_dist = 1e9;
	for(int i=0;i<N;i++)
	{
		pii p1 = point[i];
		auto lb = s.lower_bound({-1e9, p1.second - min_dist});
		auto ub = s.upper_bound({1e9, p1.second + min_dist});
		for(auto it = lb; it != ub;)
		{
			pii p2 = *it;
			double dx = p1.first - p2.first, dy = p1.second - p2.second;
			if(dx > min_dist)
			{
				auto nit = next(it);
				s.erase(it);
				it = nit;
			}
			else 
			{
				min_dist = min(min_dist, sqrt(dx*dx + dy*dy));
				it++;
			}
		}
		s.insert(p1);
	}
	
	if(min_dist - 2 * R >= D) cout << "Y\n";
	else cout << "N\n";
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int W;
	cin >> W;
	
	while(W--) solve();	
}
