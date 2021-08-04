#include<bits/stdc++.h>
using namespace std;

int findposMAX(int a[],int l,int r)
{
	if(l >= r) return l;
	
	int m = (l+r)/2;
	
	int A = findposMAX(a,l,m);
	int B = findposMAX(a,m+1,r);
	
	if(a[A] > a[B]) return A;
	return B;
}

int findMAX(int a[],int l,int r)
{
    if(l>=r) return a[l];
    int m = (l+r)/2;
    return max(findMAX(a,l,m),findMAX(a,m+1,r));
}

int findMIN(int a[],int l,int r)
{
    if(l>=r) return a[l];
    int m = (l+r)/2;
    return min(findMIN(a,l,m),findMIN(a,m+1,r));
}

long long aRn(int a,int n)
{
	if(n==0) return 1;
	if(n==1) return a;
	if(n%2 == 0) return aRn(a,(n/2)) * aRn(a,(n/2));
	else return a * aRn(a,(n/2)) * aRn(a,(n/2));
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	
}
