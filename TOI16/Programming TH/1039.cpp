#include<bits/stdc++.h>
using namespace std;

main()
{	
	int n,m;
	scanf("%d%d",&n,&m);
	
	int a,l,s;
	int round[m] = {0};
	int mspd[n] = {0};
	int win[n] = {0};
	int minT[n];
	
	for(int i=0;i<n;i++)
		minT[i] = INT_MAX;
		
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d",&a,&l,&s);
		l--;
		
		if(s > mspd[round[l]] || (s == mspd[round[l]] && l < minT[round[l]]))
		{
				minT[round[l]] = l;
				mspd[round[l]] = s;
				win[round[l]] = a;
		}
		
		round[l]++;
	}
	
	for(int i=0;i<n;i++)
	{
		if(win[i] == 0) break;
		printf("%d",win[i]);
	}
}
