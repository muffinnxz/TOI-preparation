#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
	if(b == 0) return a;
	return gcd(b,a%b);
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	
	int G = gcd(n,m);
	for(int i=1;i<=G;i++)
		if(n % i == 0 && m % i == 0)
			cout<<i<<" "<<n/i<<" "<<m/i<<"\n";
}
