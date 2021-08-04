#include<bits/stdc++.h>
#include<queue>
#include<vector>
using namespace std;

main()
{
	int n;
	cin>>n;
	
	priority_queue<int> stock;
	vector<int> ans;
	
	char c;
	int k;
	
	for(int i=0;i<n;i++)
	{
		cin>>c;
		if(c=='P')
		{
			cin>>k;
			stock.push(k);
		}
		else
		{
			if(stock.empty()) ans.push_back(-1);
			else
			{
				ans.push_back(stock.top());
				stock.pop();
			}
		}
	}
	
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<endl;
}
