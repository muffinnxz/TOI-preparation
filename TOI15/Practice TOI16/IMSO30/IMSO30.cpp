#include<iostream>
#include<math.h>
#include <bits/stdc++.h> 
using namespace std;
  
int power(int a, unsigned int n, int p) 
{ 
    int res = 1;       
    a = a % p;  
  
    while (n > 0) 
    { 
        if (n & 1) 
            res = (res*a) % p; 
        n = n>>1;  
        a = (a*a) % p; 
    } 
    return res; 
} 
int gcd(int a, int b) 
{ 
    if(a < b) 
        return gcd(b, a); 
    else if(a%b == 0) 
        return b; 
    else return gcd(b, a%b);   
} 
bool isPrimefer(unsigned int n, int k) 
{ 
   if (n <= 1 || n == 4)  return false; 
   if (n <= 3) return true; 
   while (k>0) 
   { 
       int a = 2 + rand()%(n-4);    
       if (gcd(n, a) != 1) 
          return false; 
       if (power(a, n-1, n) != 1) 
          return false; 
  
       k--; 
    } 
  
    return true; 
} 

bool isPrime(int n) 
{ 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 
int gcd2(int a, int b) 
{ 
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 
    if (a == b) 
        return a; 
    if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a); 
} 
int findLCM(int a, int b) 
{ 
    int lar = max(a, b); 
    int small = min(a, b); 
    for (int i = lar; ; i += lar) { 
        if (i % small == 0) 
            return i; 
    } 
} 
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int memf[80];
unsigned long long int fib(int n)
{
	unsigned long long int temp;
	if (memf[n]!=0) return memf[n];
	else 
	{
		if(n==0||n==1) temp=1;
		else temp=fib(n-1)+fib(n-2);
		memf[n]=temp;
		return temp;
	}
}
int memfac[1000]={0};
unsigned long long int fac(int n)
{
	if(n==1) return 1;
	else if(memfac[n]!=0) return memfac[n];
	else
	{
		memfac[n]=fac(n-1)*n;
		return memfac[n];
	}
}

main()
{
	int count=0;
	for(int i=1;i<=2562;i++)
		if(isPrime(i)) count++;
	cout<<count;
}
