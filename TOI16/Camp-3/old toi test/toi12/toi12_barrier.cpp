#include<bits/stdc++.h>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, w;
	cin >> n >> w;
	
	int arr[n+1], pref[n+1];
	memset(pref, 0, sizeof(pref));
	
	for(int i=1;i<=n;i++)
	{
		cin >> arr[i];
		pref[i] = arr[i] + pref[i-1];
	}	
	
	list<pair<int, int> > q;
	int va = 0, len = 0;
	for(int i=1;i<=n;i++)
	{
		while(!q.empty() && q.back().second >= pref[i]) q.pop_back();
		while(!q.empty() && q.front().first < i - w) q.pop_front();
		
		q.push_back({i, pref[i]});
		
		if(i == q.front().first) continue;
		
		pair<int,int> x = q.front();
		int nva = pref[i] - pref[x.first];
		
		if(va < nva)
		{
			va = nva;
			len = i - x.first;
		}
		else if(va == nva) len = min(len, i - x.first);
	}
	
	if(va < 0) cout << "0\n0";
	else cout << va << "\n" << len;
}
