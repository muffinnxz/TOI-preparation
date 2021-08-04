#include<bits/stdc++.h>
using namespace std;

typedef struct{
	int G,S,C;	
}Medal;


main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	unsigned long long tmp , sum = 0;
	
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		sum = (sum + tmp*(n-i)*(n-i+1)/2) % 2553;
	}
	cout<<sum;
}
