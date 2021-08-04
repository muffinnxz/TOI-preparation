#include<bits/stdc++.h>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	int arr[n];
	for(int i=0;i<n;i++)
		arr[i] = i+1;
	
	unordered_set<int> ban;
	int tmp;
	for(int i=0;i<m;i++)
	{
		cin>>tmp;
		ban.insert(tmp);
	}
	
	do{
		if(ban.find(arr[0]) != ban.end()) continue;
		for(int i=0;i<n;i++)
			cout<<arr[i]<<" ";
		cout<<"\n";
	}while(next_permutation(arr,arr+n));
	
}
