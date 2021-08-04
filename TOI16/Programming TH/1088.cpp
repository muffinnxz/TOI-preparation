#include<bits/stdc++.h>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	vector<pair<int,int> > flip;
	int a,b;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		flip.push_back(make_pair(a,1));
		flip.push_back(make_pair(b+1,-1));
	}
	
	flip.push_back(make_pair(n+1,0));
	
	char food;
	cin>>food;
	
	int food_int;
	if(food == 'R') food_int = 0;
	else if(food == 'G') food_int = 1;
	else food_int = 2;
	
	sort(flip.begin(),flip.end());
	
	flip[0].second %= 3;
	int S = flip.size();
	for(int i=1;i<S;i++)
		flip[i].second = (flip[i].second + flip[i-1].second) % 3;

	
	int i = 1;
	int ans = 0 , tap;
	while(i <= n)
	{
		int p = distance(flip.begin(),upper_bound(flip.begin(),flip.end(),make_pair(i,INT_MAX)));
		
		tap = food_int - flip[p-1].second;
		if(tap < 0) tap += 3;
		tap %= 3;
		
		ans += (flip[p].first - i) * tap;
		
		i = flip[p].first;
	}
	cout<<ans;
}
