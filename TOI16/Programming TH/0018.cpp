#include<bits/stdc++.h>
#include<vector>
using namespace std;

main()
{
	int n,k;
	cin>>n>>k;
	
	vector<int> seq(n-1);
		
	for(int i=0;i<n-1;i++)
		seq[i]=i+2;
	
	int nOut=0;
	int p=0;
	
	while(nOut<=k)
	{
		int temp=seq[p];
		for(int i=p;i<n-1;i+=temp)
		{
			if(seq[i]==-1) continue;
			nOut++;
			if(nOut==k) 
			{
				cout<<seq[i];	
				break;
			}
			seq[i]=-1;	
		}
		while(seq[p]==-1) p++;
		if(p>=n-1||nOut==k) break;
	}
}
