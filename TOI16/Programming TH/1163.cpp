#include<bits/stdc++.h>
using namespace std;

string makestr(int n,int d)
{
	string s;
	for(int i=0;i<d;i++)
	{
		s = char(n%2 + '0') + s;
		n/=2;
	}
	return s;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int d;
	cin>>d;
	
	for(int i=0;i<(1<<d);i++)
	{
		string s = makestr(i,d);
		for(int j=d;j>=0;j--)
		{
			if(s[j] == '0')
			{
				cout<<s<<" ";
				s[j] = '1';
				cout<<s<<"\n";
				s[j] = '0';
			}
		}
	}
}
