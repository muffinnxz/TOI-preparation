#include<bits/stdc++.h>
#include<set>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	
	int n,k;
	cin>>n>>k;
	
	int cost[n];
	for(int i=0;i<n;i++)
		cin>>cost[i];
	
	int C[n] = {0};
	C[0] = cost[0];
	
	multiset<int> set;
	
	set.insert(C[0]);
	
	for(int i=1;i<n;i++)
	{
		if(i - k > 0 ) set.erase(set.find(C[i-k-1])); 
		C[i] = cost[i] + *set.begin();
		set.insert(C[i]);
	}
	cout<<C[n-1];
}
