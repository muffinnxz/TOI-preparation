#include<bits/stdc++.h>
using namespace std;

void sport(string s,int n,int a,int b)
{
	if(a == n || b == n)
	{
		cout<<s<<"\n";
		return;
	}
	
	sport(s+"W ",n,a+1,b);
	sport(s+"L ",n,a,b+1);
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,a,b;
	cin>>n>>a>>b;
	
	sport("",n,a,b);
}
