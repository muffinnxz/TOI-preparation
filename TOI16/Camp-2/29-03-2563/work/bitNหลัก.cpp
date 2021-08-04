#include<bits/stdc++.h>
using namespace std;

int c = 0;

void rec(int n,int x)
{
	if(n == 0){
		c++;
		return;
	}
	rec(n-1,1);
	if(x != 0) rec(n-1,0);
}

main()
{
	int n;
	cin>>n;
	if(n <= 1) cout<<1;
	else
	{
		rec(n-1,0);
		rec(n-1,1);
		cout<<c;		
	}
}
