#include<bits/stdc++.h>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	priority_queue<int,vector<int>,greater<int> > empty_park;
	int price[n],weight[m];
	
	for(int i=0;i<n;i++)
	{
		cin>>price[i];
		empty_park.push(i);
	}
	
	for(int i=0;i<m;i++)
		cin>>weight[i];
	
	queue<int> park_queue;
	map<int,int> park_where;
	
	int tmp;
	unsigned long long profit = 0;
	for(int i=0;i<m*2;i++)
	{
		cin>>tmp;
		
		if(tmp >= 0)
		{
			tmp--;
			if(!empty_park.empty())
			{
				park_where[tmp] = empty_park.top();
				profit += weight[tmp] * price[empty_park.top()];
				empty_park.pop();
			}
			else park_queue.push(tmp);
		}
		else
		{
			tmp = abs(tmp) - 1;
			empty_park.push(park_where[tmp]);
			if(!park_queue.empty())
			{
				tmp = park_queue.front();
				park_queue.pop();
				
				park_where[tmp] = empty_park.top();
				profit += weight[tmp] * price[empty_park.top()];
				empty_park.pop();
			}
		}
	}
	
	cout<<profit;
}
