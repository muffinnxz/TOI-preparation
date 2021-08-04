/*
TASK: high
LANG: C++
AUTHOR: Jeanipat Lapsuwannawong
CENTER: WU
*/

#include<bits/stdc++.h>
using namespace std;

main()
{
	int tmp;
	cin>>tmp;
	if(tmp == -1 || tmp == -2) cout<<"0";
	else
	{
		int h = 1;
		int member = 2;
		while(true)
		{
			int null = 0;
			for(int i=0;i<member;i++) 
			{
				cin>>tmp;
				if(tmp == -1) null++;
				else if(tmp == -2) break;
			}
			member = member - null;
			if(tmp == -2 || member <= 0) break;
			member = member * 2;
			h++;	
		}
		cout<<h;
	}
}
