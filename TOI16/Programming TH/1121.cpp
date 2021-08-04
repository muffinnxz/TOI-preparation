#include<bits/stdc++.h>
using namespace std;

#define endll '\n'

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin>>t;
	
	while(t--)
	{
		string s;
		cin>>s;
		
		stack<char> stc;
		
		int len = s.length() , i;
		for(i=0;i<len;i++)
		{
			if(s[i] == ')')
			{
				if(!stc.empty() && stc.top() == '(') stc.pop();
				else break;
			}
			else if(s[i] == ']')
			{
				if(!stc.empty() && stc.top() == '[') stc.pop();
				else break;
			}
			else if(s[i] == '}')
			{
				if(!stc.empty() && stc.top() == '{') stc.pop();
				else break;
			}
			else stc.push(s[i]);
		}
		
		if(i == len && stc.empty()) cout<<"yes\n";
		else cout<<"no\n";
	}
}
