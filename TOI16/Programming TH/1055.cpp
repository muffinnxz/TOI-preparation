#include<bits/stdc++.h>
using namespace std;

list<int> line;

list<int>::iterator movePointer(list<int>::iterator it,int n)
{
	for(int i=0;i<n;i++)
	{
		it++;
		if(it == line.end()) it = line.begin();
	}
	return it;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,k;
	cin>>n>>k;
	
	int tmp;
	for(int i=0;i<n;i++)
	{
		cin>>tmp;
		line.push_back(tmp);
	}	
	
	int win[k] = {0};
	int p = 0;
	list<int>::iterator it1,it2;
	it1 = line.begin();
	while(!line.empty())
	{
		cin>>tmp;
		it1 = movePointer(it1,tmp);
		win[p] += *it1;
		it2 = it1;
		it1 = movePointer(it1,1);
		line.erase(it2);
		if(line.empty()) break;
		p = (p+1)%k;
	}
	for(int i=0;i<k;i++)
		cout<<win[i]<<endl;
}
