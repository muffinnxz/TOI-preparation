#include<bits/stdc++.h>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int P;
	cin>>P;
	
	int p1 = P,p2 = P,c1 = 0, c2 = 0;
	
	int tmp;
	while(p1 > 0 && p2 > 0)
	{
		cin>>tmp;
		if(tmp%2 == 1)
		{
			c1++;
			c2 = 0;
			if(c1 >= 3) p2 -= 3;
			else p2--;
		}
		else
		{
			c1 = 0;
			c2++;
			if(c2 >= 3) p1 -= 3;
			else p1--;
		}
		
		if(p1 <= 0) cout<<"0\n"<<tmp;
		else if(p2 <= 0) cout<<"1\n"<<tmp;
	}	
	
}
