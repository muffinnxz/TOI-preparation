#include<bits/stdc++.h>
using namespace std;

long long Cnr(int n, int r) 
{ 
    long long p = 1, k = 1; 
    
    if (n - r < r)  r = n - r; 
  
    if (r != 0) 
	{ 
        while (r) 
		{ 
            p *= n; 
            k *= r; 
            
            long long m = gcd(p, k); 
  
            p /= m; 
            k /= m; 
  
            n--; 
            r--; 
        }
    } 
  	else p = 1; 
  
    return p; 
} 

main()
{
	
}
