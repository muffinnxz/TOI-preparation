#include<bits/stdc++.h>
using namespace std;

#define endll "\n"

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	int cloth[n+1][71];
	memset(cloth,0,sizeof(cloth));
	int r,c,x,mx = 0;
	while(n--)
	{
		cin>>r>>c>>x;
		mx = max(mx,r);
		for(int i=c;i<c+x && i<=70;i++)
			cloth[r][i] = 1;
	}
	for(int i=1;i<=mx;i++)
	{
		for(int j=1;j<=70;j++)
			if(cloth[i][j]) cout<<"x";
			else cout<<"o";
		cout<<endll;
	}
}
