#include<bits/stdc++.h>
using namespace std;
#define ll long long int

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll n,k;
	cin>>n>>k;
	
	string s;
	cin>>s;
	
	ll pref = 0;
	map<ll,ll> occur;
	occur[0] = -1;

	ll len = 0;
	for(ll i=0;i<n;i++)
	{
		if(s[i] == 'O') pref++;
		else pref -= k;
		
		if(occur.find(pref) == occur.end()) occur[pref] = i;
		else len = max(len,i - occur[pref]);
	}
	
	cout<<len;
}
