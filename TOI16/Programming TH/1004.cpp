#include<bits/stdc++.h>
#include<vector>
#include<set>
using namespace std;

typedef struct{
	int first;
	int second;
}PAIR;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int nc,ns;
	cin>>nc>>ns;
	set<int> std[nc+1];
	
	int a,b;
	for(int i=0;i<ns;i++)
	{
		cin>>a>>b;
		std[a].insert(b); 
	}
	
	char c;
	int n;
	
	vector<PAIR> line;
	vector<int> ans;
	int ClassinLine[nc+1] = {0};
	while(true)
	{
		cin>>c;
		if(c == 'X') break;
		if(c == 'E') 
		{
			cin>>n;
			int room;
			for(int i=1;i<=nc;i++)
				if(std[i].find(n) != std[i].end())
				{
					room = i;
					break;
				}
			if(ClassinLine[room] == 0)
			{
				PAIR tmp = {room,n};
				line.push_back(tmp);
			}
			else
			{
				int i = line.size()-1;
				while(line[i].first != room) i--;
				PAIR tmp = {room,n};
				if(i == line.size() - 1) line.push_back(tmp);
				else line.insert(line.begin() + i + 1,tmp);	
			}
			ClassinLine[room]++;
		}
		else
		{
			ans.push_back(line[0].second);
			ClassinLine[line[0].first]--;
			line.erase(line.begin());
		}	
	}
	vector<int>::iterator it;
	for(it = ans.begin();it != ans.end();it++)
		cout<<*it<<endl;
	cout<<0;
}
