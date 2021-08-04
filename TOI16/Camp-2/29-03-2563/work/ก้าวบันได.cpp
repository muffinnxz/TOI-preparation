#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<unsigned long long> path;

unsigned long long walk(int n)
{
	if(path[n] != 0) return path[n];
	path[n] = walk(n-1) + walk(n-2) + walk(n-3);
	return path[n];
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	if(n == 0) cout<<1;
	else if(n == 1) cout<<1;
	else if(n == 2) cout<<2;
	else
	{
		for(int i=0;i<=n;i++)
			path.push_back(0);
			
		path[0] = 1;
		path[1] = 1;
		path[2] = 2;
		
		walk(n);
		
		cout<<path[n];
	}
}
