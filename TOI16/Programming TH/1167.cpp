#include<bits/stdc++.h>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin>>s;
	
	int dir[4] = {0,0,0,0};
	memset(dir,0,sizeof(dir));
	
	char *p = &s[0];
	while(*p != '\0')
	{
		if(*p == 'N') dir[0]++;
		else if(*p == 'S') dir[1]++;
		else if(*p == 'E') dir[2]++;
		else dir[3]++;
		p++;
	}
	
	int k;
	cin>>k;
	
	int pos = max(dir[0],dir[1]) + max(dir[2],dir[3]) , neg = min(dir[0],dir[1]) + min(dir[2],dir[3]);
	
	while(k)
	{
		if(neg > 0) neg--;
		else pos--;
		k--;
	}
	
	cout<<(pos - neg) * 2;
}
