#include <bits/stdc++.h> 
using namespace std; 

int power(long double x, long double y, long double p) 
{ 
    int res = 1;     
    x = fmod(x,p);  
    while (y > 0) 
    { 
        if (fmod(y,2) == 1) 
            res = (int)fmod(res*x,p); 
  
        y = (int)y/2;
        x = fmod(x*x,p); 
    } 
    return res; 
} 

long double gcd(long double a,long double b)
{
	if(b == 0) return a;
	return gcd(b,fmod(a,b));
}

bool isPrime(long double n, int k) 
{ 
	if (n <= 1 || n == 4) return false; 
	if (n <= 3) return true; 

	while (k>0) 
	{ 
		long double a = 2 + (int)fmod(rand(),n-4); 
		if (gcd(n, a) != 1) return false; 
		if (power(a, n-1, n) != 1) return false; 
		k--; 
	}
	return true; 
} 

main() 
{ 
	long double n;
	cin>>n;
	
	if(isPrime(n,3)) cout<<"yes";
	else cout<<"no";
} 

