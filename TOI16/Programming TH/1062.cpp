#include<bits/stdc++.h>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	string a,b,c;
	cin>>a>>b>>c;
	
	char tmp[3];
	for(int i=m-1;i>=0;i--)
	{
		for(int j=0;j<n;j++)
		{
			tmp[0] = a[j]; tmp[1] = c[i]; tmp[2] = b[j];
			sort(tmp,tmp+3);
			c[i] = tmp[1];
		}
	}
	
	cout<<c;
}
