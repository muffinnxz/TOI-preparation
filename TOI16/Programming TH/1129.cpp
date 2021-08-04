#include<bits/stdc++.h>
using namespace std;

list<int> line;
list<int>::iterator it,E;

void move(int p)
{
	for(int i=0;i<p;i++)
	{
		it++;
		if(it == line.end()) it = line.begin();
	}
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,k;
	cin>>n>>k;
	
	for(int i=1;i<=n;i++)
		line.push_back(i);
	
	it = line.begin();
	move((k-1) % n);
	while(n)
	{
		cout<<*it<<"\n";
		E = it;
		move(1);
		line.erase(E);
		n--;
		if(line.empty()) break;
		move((k-1) % n);
	}
}
