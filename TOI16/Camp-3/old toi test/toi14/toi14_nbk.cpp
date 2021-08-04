#include<bits/stdc++.h>
using namespace std;
#define endll "\n"

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	pair<int, int> ep[n]; // (int, int) object pair -> first, second
	
	cin >> ep[0].first;
	ep[0].second = 0;
	
	for(int i=1;i<n;i++){
		cin >> ep[i].first;
		ep[i].first += ep[i-1].first;
		ep[i].second = i; 
	}
	
	sort(ep, ep+n);
	
	int maxEp = 0;
	for(int i=0;i<n;i++){
		maxEp = max(maxEp, ep[i].second);
		ep[i].second = maxEp;
	}
	
	int tmp;
	while(q--){
		cin >> tmp;
		if(tmp > ep[n-1].first) cout << n << endll;
		else if(tmp < ep[0].first) cout << 0 << endll;
		else{
			int idx = upper_bound(ep, ep+n, make_pair(tmp, INT_MAX)) - ep;
			cout << ep[idx-1].second + 1 << endll;
		}
	}
}
