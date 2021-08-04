#include<bits/stdc++.h>
using namespace std;

#define endll "\n"

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	bool nugget[150];
	memset(nugget,false,sizeof(nugget));
	
	nugget[6] = true;
	nugget[9] = true;
	nugget[20] = true;
	
	bool ans = false;
	for(int i=1;i<=n;i++)
	{
		if(nugget[i])
		{
			cout<<i<<endll;
			ans = true;
			nugget[i+6] = true;
			nugget[i+9] = true;
			nugget[i+20] = true;
		}
	}
	
	if(!ans) cout<<"no";
}
