#include<bits/stdc++.h>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	char tmp;
	list<char> line;
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		line.push_back(tmp);
	}
	
	list<char>::iterator it1,it2;
	it1 = line.begin(); 
	it2 = line.begin(); it2++;
	
	while(it2 != line.end())
	{
		
		if(*it1 == *it2)
		{
			while(*it1 == *it2 && it1 != line.begin() && it2 != line.end())
			{
				it1--;
				it2++;
			}
			if(*it1 != *it2) it1++;
			else if(it2 != line.end()) it2++;
			line.erase(it1,it2);
			it1 = it2;
			it1--;
		}
		it1++;
		it2++;
	}
	
	cout<<line.size()<<endl;
	if(line.size() == 0) cout<<"empty";
	else
	while(!line.empty())
	{
		cout<<line.back();
		line.pop_back();
	}
	
}
