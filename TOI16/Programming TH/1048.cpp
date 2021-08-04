#include<bits/stdc++.h>
using namespace std;

main()
{
	int k;
	unsigned long int n;
	cin>>k>>n;
	
	unsigned long int temp;
	int ans = 0;
	for(int i=0;i<=n-1;i++)
	{
		temp = i ^ (i+1);
		for(int j=0;j<k;j++)
		{
			ans += temp%2;
			temp/=2;
		}
	}
	cout<<ans;
}
