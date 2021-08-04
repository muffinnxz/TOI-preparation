#include<bits/stdc++.h>
using namespace std;

long long getzero(long long n)
{
	long long count = 0;
	for(long long i = 5 ; n / i > 0 ; i *= 5)
		count += n/i;
	return count;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long x,y,k;
	cin>>x>>y>>k;
	
	long long p = getzero(x);
	long long ans = p % k;
	
	for(long long i=x+1;i<=y;i++)
	{
		long long tmp = i;
		while(tmp / 5 > 0 && tmp % 5 == 0) {
			p++;
			tmp /= 5;
		}
		ans = (ans + p) % k;
	}
	
	cout<< ans;	
}
