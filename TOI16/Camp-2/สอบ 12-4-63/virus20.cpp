/*
TASK: virus
LANG: C++
AUTHOR: Jeanipat Lapsuwannawong
CENTER: WU
*/

#include<bits/stdc++.h>
using namespace std;

main()
{
	int n,m;
	cin>>n;
	
	string virus,s;
	cin>>virus;
	
	int key = 0;
	for(int i=0;i<n;i++)
		key += (int)(virus[i] - '0');
	
	key = key % 26;
	
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>s;
		int len = s.length();
		for(int j=0;j<len;j++)
			s[j] = 'A' + ((s[j] - 'A') + key) % 26;	
		cout<<s<<"\n";
	}
}
