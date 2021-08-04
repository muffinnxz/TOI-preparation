#include<bits/stdc++.h>
using namespace std;

long long gcd(long a,long b)
{
	if(b == 0) return a;
	return gcd(b,a%b);
}

main()
{
	long long a,b;
	cin>>a>>b;
	cout<<(a*b)/gcd(a,b);
}
