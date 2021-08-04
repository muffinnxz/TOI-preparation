#include<bits/stdc++.h>
using namespace std;

bool isPrime(long double n)
{
	if(n<=1) return false;
	if(n<=3) return true;
	if(fmod(n,2) == 0 || fmod(n,3) == 0) return false;
	for(int i=5;i*i<=n;i+=6)
		if(fmod(n,i) == 0 || fmod(n,(i+2)) == 0) return false;
	return true;
}

main()
{
	long double n;
	cin>>n;
	
	if(isPrime(n)) cout<<"yes";
	else cout<<"no";
}
