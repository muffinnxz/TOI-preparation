#include <bits/stdc++.h> 
using namespace std; 
  
int power(long double x, long double y, long double p) 
{ 
    int res = 1;     
    x = (int)fmod(x,p);  
    while (y > 0) 
    { 
        if ((int)fmod(y,2) == 1) 
            res = (int)fmod(res*x,p); 
  
        y = (int) y/2;
        x = fmod(x*x,p); 
    } 
    return res; 
} 
  
bool miillerTest(long double d, long double n) 
{ 
    long double a = 2 + (int)fmod(rand(),n-4); 
  
    long double x = power(a, d, n); 
  
    if (x == 1  || x == n-1) return true; 

    while (d != n-1) 
    { 
        x = (int)fmod(x*x,n); 
        d *= 2; 
  
        if (x == 1)      return false; 
        if (x == n-1)    return true; 
    } 
  
    return false; 
} 
  
bool isPrime(long double n, int k) 
{ 
    if (n <= 1 || n == 4)  return false; 
    if (n <= 3) return true; 
  
    long double d = n - 1; 
    while (fmod(d,2) == 0) d = (int) d/2; 
  
    for (int i = 0; i < k; i++) 
         if (!miillerTest(d, n)) return false; 
    return true; 
} 

main() 
{ 
    long double n;
    cin>>n;
    
    if (isPrime(n, 3)) cout<<"yes";
	else cout<<"no";  
} 
