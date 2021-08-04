#include<bits/stdc++.h>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin>>s;
	
	char *p = &s[0];
	int a = 0 , b = 0;
	while(*p != '\0')
	{
		if(*p == '(') a++;
		else if(a > 0) a--;
		else b++;
		p++;
	}
	cout<<a+b;
}
