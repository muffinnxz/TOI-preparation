#include<bits/stdc++.h>
using namespace std;

#define endll '\n'

bool isPrime(int n)
{
	if(n <= 1) return false;
	if(n <= 3) return true;
	if(n % 2 == 0 || n % 3 == 0) return false;
	for(int i=5;i*i<=n;i+=6)
		if(n % i == 0 || n % (i+2) == 0) return false;
	return true;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,k;
	cin>>n>>k;
	
	int req = 0;
	for(int i=2;i<=n;i++)
		if(isPrime(i)) req++;
	
	if(req - k <= 0) cout<<"0";
	else cout<<req-k;
}
