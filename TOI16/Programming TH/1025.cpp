#include<bits/stdc++.h>
#include<iomanip>
using namespace std;

double gcd(double a,double b)
{
	if(b==0) return a;
	return gcd(b,fmod(a,b));
}

main()
{
	int n;
	cin>>n;
	double arr[n];
	
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	double lcm=arr[0];
	for(int i=1;i<n;i++)
		lcm=(lcm*arr[i])/(gcd(lcm,arr[i]));
		
	cout<<fixed<<setprecision(0);
	cout<<lcm;
}
