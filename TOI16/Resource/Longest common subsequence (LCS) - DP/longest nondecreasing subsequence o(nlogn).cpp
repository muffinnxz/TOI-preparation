#include<bits/stdc++.h>
#define pi pair<int,int>
#define pii pair<int, pi>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	int x;
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		cin >> x;
		auto it = upper_bound(v.begin(), v.end(), x);
		if(it == v.end()) v.push_back(x);
		else *it = x;
	}
		
	cout << v.size();
}
