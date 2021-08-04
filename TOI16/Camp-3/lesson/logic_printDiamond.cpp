#include<bits/stdc++.h>
using namespace std;

#define endll "\n"
#define pii pair<long long int,long long int>
#define piii pair<long long int,pii>
const int div_prime = 1000000007;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	char ch;
	int n,m;
	cin>>ch>>n>>m;
	
	int k = 2*n+1;
	for(int i=0;i<m*k;i++)
	{
		for(int j=0;j<m*k;j++)
		{
			int x = i % k, y = j % k;
			if(i==j || i+j == m*k-1) cout<<'#';
			else if(x==y || x==n || y==n || x+y == 2*n) cout<<'+';
			else if(y<n-x || x>y+n || y>n+x || x+y>3*n) cout<<'.';
			else cout<<ch;
		}
		cout<<endll;
	}
}
