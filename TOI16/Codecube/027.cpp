#include<bits/stdc++.h>
using namespace std;

vector<int> dp(1<<21, INT_MAX)];

int solve(int s)
{
	if(dp[s]) return dp[s];
	
	for(int i=0;i<n-1;i++)
	{
		int ne	
	}
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	int s, tmp, k = n-1;
	while(k >= 0)
	{
		cin >> tmp;
		s += tmp * int(1<<(k--));
	}
	
	solve(s);
	
	if(dp[0] == INT_MAX) cout <<"-1";
	else cout << dp[0];
}
