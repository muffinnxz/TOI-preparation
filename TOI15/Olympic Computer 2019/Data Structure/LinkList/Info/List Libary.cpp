#include<list>
#include<iostream>
using namespace std;
main()
{
	list<int> n;
	list<int>::iterator it;
	
	n.push_back(1);
	n.push_back(2);
	n.push_back(3);
	n.push_back(4);
	n.push_back(1);
	n.reverse();
	n.unique();
	cout<<n.back();
	cout<<"List :"<<'\n';
	it=n.begin();
	it++;
	n.erase(it);

		for(it=n.begin();it!=n.end();it++)
			cout<<"- "<<*it<<endl;
	
}
