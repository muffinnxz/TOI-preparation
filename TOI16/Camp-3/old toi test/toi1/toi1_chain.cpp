#include<bits/stdc++.h>
using namespace std;

#define endll "\n"

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int l,n;
	cin>>l>>n;
	
	string word[n];
	for(int i=0;i<n;i++)
		cin>>word[i];
	
	int dif;
	for(int i=1;i<n;i++)
	{
		dif = 0;
		for(int j=0;j<l;j++)
		{
			if(word[i][j] != word[i-1][j]) dif++;
			if(dif > 2)
			{
				cout<<word[i-1];
				break;
			}
		}
		if(dif > 2) break;
	}
	if(dif <= 2) cout<<word[n-1];
}
