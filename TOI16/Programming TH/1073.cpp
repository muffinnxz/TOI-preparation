#include<bits/stdc++.h>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,time,l;
	cin>>n>>time>>l;
	
	pair<int,char> ant[l];
	for(int i=0;i<l;i++)
		cin>>ant[i].first>>ant[i].second;
	
	int t;
	for(int i=0;i<l;i++)
	{
		t = time;
		if(ant[i].second == 'D')
		{
			if(ant[i].first + t <= n) ant[i].first += t;
			else
			{
				t = t - n + ant[i].first;
				if( (t/n) % 2 == 0) ant[i].first = n - (t%n);
				else ant[i].first = (t%n); 			
			}			
		}
		else
		{
			if(ant[i].first - t >= 0) ant[i].first -=t;
			else
			{
				t = t - ant[i].first;
				if( (t/n) % 2 == 0) ant[i].first = (t%n);
				else ant[i].first = n - (t%n);
			}
		}
	}
	
	sort(ant,ant+l);
	
	for(int i=0;i<l;i++)
		cout<<ant[i].first<<" ";
}
