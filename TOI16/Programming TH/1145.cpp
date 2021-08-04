#include<bits/stdc++.h>
using namespace std;

string findLCSmultiStr(vector<string> str)
{
	int n = str.size();
	
	string lcs = "";
	
	for(int i=0;i<n;i++)
	{
		string s = str[i];
		int len = s.length();
		
		for(int j=0;j<len;j++)
		{
			for(int k=1;k<=len-j;k++)
			{
				string sub = s.substr(j,k);
				
				int count = 0;
				for(int l=0;l<n;l++)
				{
					if(l == i) continue;
					if(str[l].find(sub) != string::npos)
						count++;
				}

				if(count >= 2 && sub.length() >= lcs.length())
				{
					if(sub.length() != lcs.length()) lcs = sub;
					else lcs = min(lcs,sub);
				}
			}
		}
	}
	
	return lcs;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<string> str(4);
	for(int i=0;i<4;i++)
	{
		cin>>str[i];
		auto it = &str[i][0];
		while(*it != '\0')
		{
			*it = tolower(*it);
			it++;
		}
	}
	
	cout<<findLCSmultiStr(str);
}
