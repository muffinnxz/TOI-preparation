#include<bits/stdc++.h>
#include<vector>
#include<list>
using namespace std;

main()
{
	int n;
	cin>>n;
	
	vector<int> skyline(256,0);
	int Li,Hi,Ri;
	int Ls=256,Rs=0;
	for(int i=0;i<n;i++)
	{
		cin>>Li>>Hi>>Ri;
		
		if(Li<Ls) Ls=Li;
		if(Ri>Rs) Rs=Ri;
		 
		for(int j=Li;j<Ri;j++)
			if(Hi>skyline[j]) skyline[j]=Hi;
			
	}
	
	for(int i=Ls;i<Rs;i++)
		cout<<skyline[i]<<" ";
	cout<<endl;
	
	int temp=-1;
	cout<<Ls<<" "<<skyline[Ls]<<" ";
	for(int i=Ls+1;i<Rs;i++)
	{
		if(skyline[i]==0) continue;
		if(skyline[i]!=skyline[i-1]) cout<<i<<" "<<skyline[i]<<" ";
		if(skyline[i+1]==0) cout<<i+1<<" "<<"0 ";
	}

}
