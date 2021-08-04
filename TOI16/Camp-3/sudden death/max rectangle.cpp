#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	stack<int> stc;
	int mx = 0, i = 0;
	while(i < n)
	{
		if(stc.empty() || arr[i] >= arr[stc.top()]) stc.push(i++);
		else
		{
			int tmp = stc.top();
			stc.pop();
			if(stc.empty()) mx = max(mx, i * arr[tmp]);
			else mx = max(mx, (i - stc.top() - 1) * arr[tmp]);
 		}
	}
	
	while(!stc.empty())
	{
		int tmp = stc.top();
		stc.pop();
		if(stc.empty()) mx = max(mx, i * arr[tmp]);
		else mx = max(mx, (i - stc.top() - 1) * arr[tmp]);
	}
	
	cout << mx << "\n";
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--) solve();
}
