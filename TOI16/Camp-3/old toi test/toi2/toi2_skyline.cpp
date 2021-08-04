#include<bits/stdc++.h>
using namespace std;

#define endll "\n";

main()
{
	int n;
	cin>>n;
	
	int skyline[260];
	memset(skyline,0,sizeof(skyline));
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

	cout<<Ls<<" "<<skyline[Ls]<<" ";
	for(int i=Ls+1;i<Rs;i++)
		if(skyline[i]!=skyline[i-1])	cout<<i<<" "<<skyline[i]<<" ";
	cout<<Rs<<" 0";
}
