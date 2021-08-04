#include<bits/stdc++.h>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,k,a;
	cin>>n>>k>>a;
	
	int page = 0, tmp , book[10005];
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		page += tmp;
		book[page]++;
	}
	
	book[page+1] = 0;
	
	for(int i=page;i>=1;i--)
		book[i] += book[i+1];
	
	int start = 0 , max_day = 0;
	for(int i=1;i<=page;i++)
	{
		int p = i, lastday = INT_MAX , d = 0 , j = 0;
		while(p <= page && j < k)
		{
			if(book[p] < lastday) 
			{
				d++;
				lastday = book[p];
			}
			p += a;
			j++;
		}
		if(d > max_day)
		{
			start = i;
			max_day = d;
		}
	}
	
	cout<<start<<" "<<max_day;
}
