#include<bits/stdc++.h>
using namespace std;

#define endll "\n"

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int Nc,Ns,c,s;
	cin>>Nc>>Ns;
	
	map<int,int> std_info;
	for(int i=0;i<Ns;i++)
	{
		cin>>c>>s;
		std_info[s] = c-1;
	}
	
	int mem_class[Nc];
	memset(mem_class,0,sizeof(mem_class));
	
	list<int> line;
	char cmd;
	while(true)
	{
		cin>>cmd;
		if(cmd == 'X') break;
		else if(cmd == 'E')
		{
			cin>>s;
			c = std_info[s];
			if(mem_class[c] == 0) line.push_back(s);
			else
			{
				list<int>::iterator it = line.end();
				while(std_info[*--it] != c);
				line.insert(++it,s);
			}
			mem_class[c]++;
		}
		else
		{
			cout<<line.front()<<endll;
			mem_class[std_info[line.front()]]--;
			line.pop_front();
		}
	}
	cout<<"0";
}
