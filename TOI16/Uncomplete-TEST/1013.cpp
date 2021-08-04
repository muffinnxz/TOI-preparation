#include<bits/stdc++.h>
#include<string>
#include<list>
using namespace std;

char sym[] = {'^','*','+',')'};

string op(int n,string s,char c,int tmp)
{
	int p = 0;
	while(s[p] != '\0')
	{
		if(s[p] == c)
		{
			if(n == 1) 
			{
				if(c == ')') return s.substr(0,p+1);
				return s.substr(0,p);
			}
			if(c == ')') return op(n-1,s.substr(p+2),c,tmp);
			return op(n-1,s.substr(p+1),c,tmp);
		}
		p++;
	}
	if(n != tmp && n == 1) return s;
	return "NULL";
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin>>s;
	
	int n;
	cin>>n;
	
	list<int> cmd;
	string a,b;
	int tmp,fe;
	
	for(int i=0;i<n;i++)
	{
		while(true)
		{
			cin>>tmp;
			if(tmp != 0) cmd.push_back(tmp);
			else break;
		}
		
		a = s;
			
		while(!cmd.empty())
		{
			fe = cmd.front();
			cmd.pop_front();
			
			for(int j=3;j>=0;j--)
			{
				b = op(fe,a,sym[j],fe);
				if(b != "NULL") break;
			}
			
			if(b == "NULL")
			{
				cmd.clear();
				break;
			}
			
			a = b;
		}
		
		cout<<b<<endl;
		
	}
	
}
