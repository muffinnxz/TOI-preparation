#include<bits/stdc++.h>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	int wu[n], actor[n];
	for(int i=0;i<n;i++)
		cin >> wu[i];
	for(int i=0;i<n;i++)
		cin >> actor[i];
		
	sort(wu, wu+n);
	sort(actor, actor+n);
	
	int ans = 0;
	for(int i=0;i<n;i++)
		ans += abs(wu[i] - actor[i]);
	
	cout << ans;
}
