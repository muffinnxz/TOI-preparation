#include<bits/stdc++.h>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,k;
	cin>>n>>k;
	
	int work[n];
	for(int i=0;i<n;i++)
		cin>>work[i];

	sort(work,work+n);
	
	int x = 0;
	int i = 0;
	
	if(n%k != 0)
	{
		x += work[n%k-1];
		i = n%k-1; 
		while(i < n)
		{
			if(i+k < n) x += work[i+k];
			else break;
			i += k;
		}
	}
	else
	{
		while(i<n)
		{
			if(i+k-1<n) x += work[i+k-1];
			else break;
			i += k;
		}
	}
	cout<<x;
}
