#include<bits/stdc++.h>
using namespace std;

#define endll "\n"

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int dp[25][2],q=1,s=0,w=1;
	for(int i=0;i<25;i++)
	{
		w = w+s+q;
		s = w-s-q;
		dp[i][0] = s, dp[i][1] = w;
	}
	
	int tmp;
	while(true)
	{
		cin>>tmp;
		if(tmp != -1) cout<<dp[tmp][0]<<" "<<dp[tmp][1]<<endll;
		else break;
	}
}
