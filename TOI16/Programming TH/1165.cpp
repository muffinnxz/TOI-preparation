#include<bits/stdc++.h>
using namespace std;

unsigned long long gcd(unsigned long long a , unsigned long long b)
{
	if(b == 0) return a;
	return gcd(b,a%b);
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	unsigned long long n,m,tmp;
	cin>>n;
	
	cin>>tmp;
	m = tmp;

	for(int i=1;i<n;i++)
	{
		cin>>tmp;
		m = gcd(m,tmp);
	}
	
	if(m == 1) cout<<"1";
	else
	{
		unsigned long long ans = 0;
		unsigned long long i;
		for(i=1;i*i<m;i++)
			if(m % i == 0) ans += 2;
		if(i*i == m) ans++;
		cout<<ans;
	}
}
