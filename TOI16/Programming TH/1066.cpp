#include<bits/stdc++.h>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	list<int> line;
	list<int>::iterator it1,it2;
	
	int tmp;
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		line.push_back(tmp);
	}
	
	int ans = 0;
	while(line.size() > 1)
	{
		it1 = line.begin(); it2 = line.begin(); it2++;
		for(auto i = line.begin();i != line.end();i++)
		{
			auto j = i; j++;
			if(j == line.end()) break;
			if(abs(*j - *i) >= abs(*it1 - *it2))
			{
				it1 = i;
				it2 = j;
			}
		}
		ans+=abs(*it2-*it1);
		line.erase(it1,++it2);
	}
	cout<<ans;
}
