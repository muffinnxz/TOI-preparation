#include<bits/stdc++.h>
using namespace std;

void bis(vector<int> flip,int l,int r,int x)
{
	int m = (l+r)/2;
	if(x >= flip[m] && x < flip[m+1])
	{
		printf("%d\n",flip[m+1] - flip[m]);
		return;
	}
	if(x > flip[m]) bis(flip,m,r,x);
	else bis(flip,l,m,x);
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	
	vector<int> flip;
	
	flip.push_back(1);
	flip.push_back(n+1);
	int a,b;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		flip.push_back(a);
		flip.push_back(a+b);
	}
	
	sort(flip.begin(),flip.end());
	vector<int>::iterator it = unique(flip.begin(),flip.begin() + (m*2) +2) ;
	flip.resize(distance(flip.begin(),it));
	sort(flip.begin(),flip.end());
	
	for(int i=0;i<q;i++)
	{
		scanf("%d",&a);
		bis(flip,0,flip.size()-1,a);
	}
}
