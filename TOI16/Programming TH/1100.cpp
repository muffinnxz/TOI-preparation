#include<bits/stdc++.h>
using namespace std;

int ctoi(char n)
{
	return (int)(n - '0');
}

unsigned long long gcd(unsigned long long a,unsigned long long b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

unsigned long long Cnr(unsigned long long  n,unsigned long long  r)
{
	if(n < r) return 0;
	
	unsigned long long p = 1,k = 1;
	if(n - r < r) r = n - r;
	
	if(r != 0)
	{
		while(r)
		{
			p *= n;
			k *= r;
			unsigned long long m = gcd(p,k);
			p /= m;
			k /= m;
			n--;
			r--;
		}
		return p;
	}
	else return 1;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	unsigned long long A[10] = {0},B[10] = {0},C[10] = {0},AB[100] = {0},AC[100] = {0},BC[100] = {0},ABC[1000] = {0};
	char tmp[4];	
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		A[ctoi(tmp[0])]++;
		B[ctoi(tmp[1])]++;
		C[ctoi(tmp[2])]++;
		AB[ctoi(tmp[0]) * 10 + ctoi(tmp[1])]++;
		AC[ctoi(tmp[0]) * 10 + ctoi(tmp[2])]++;
		BC[ctoi(tmp[1]) * 10 + ctoi(tmp[2])]++;
		ABC[ctoi(tmp[0]) * 100 + ctoi(tmp[1]) * 10 + ctoi(tmp[2])]++;
	}
	
	unsigned long long X = 0, Y = 0, Z = 0;
	
	for(int i=0;i<10;i++)
		X += Cnr(A[i],2) + Cnr(B[i],2) + Cnr(C[i],2);
	for(int i=0;i<100;i++)
		Y += Cnr(AB[i],2) + Cnr(AC[i],2) + Cnr(BC[i],2);
	for(int i=0;i<1000;i++)
		Z += Cnr(ABC[i],2);
		
	cout<<X-Y+Z;
}
