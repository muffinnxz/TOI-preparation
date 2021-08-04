#include<bits/stdc++.h>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string a,b;
	cin>>a>>b;
	
	int len = a.length();
	for(int i=0;i<len;i++)
	{
		a[i] = toupper(a[i]);
		b[i] = toupper(b[i]);
	}
	
	int key[len];
	bool ans = true;
	for(int i=0;i<len;i++)
	{
		key[i] = a[i] - b[i];
		if(key[i] < 0) key[i] += 26;
		if(key[i] > 9) 
		{
			ans = false;
			break;
		}
	}
		
	if(ans)
		for(int i=0;i<len;i++)
			cout<<key[i];
	else cout<<"R.I.P.";
}
