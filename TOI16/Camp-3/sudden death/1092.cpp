#include<bits/stdc++.h>
using namespace std;

int n, m;
int soldier[100001], parent[100001];

int fp(int u)
{
	if(parent[u] == 0) return u;
	return parent[u] = fp(parent[u]);
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=1;i<=n;i++)
		cin >> soldier[i];
	
	memset(parent, 0, sizeof(parent));
	
	int a, b;
	for(int i=0;i<m;i++)
	{
		cin >> a >> b;
		int ga = fp(a), gb = fp(b);
		
		if(ga == gb) cout <<"-1\n";
		else
		{
			if(soldier[ga] > soldier[gb] || (soldier[ga] == soldier[gb] && ga < gb)) 
			{
				cout << ga << "\n";
				soldier[ga] += soldier[gb] / 2;
				parent[gb] = ga;
			}
			else
			{
				cout << gb << "\n";
				soldier[gb] += soldier[ga] / 2;
				parent[ga] = gb;
			}   
		}
	}
}
