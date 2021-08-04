#include<iostream>
#include<list>
using namespace std;
bool check2(int n)
{
	list<int> z;
	int combo=0;
	while(n!=0)
	{
		z.push_front(n%2);
		n/=2;
	}
	while(!z.empty())
	{
		if(z.front()==1)
			combo++;
		else combo=0;
		if(combo==3) return true;
		z.pop_front();
	}
	return false;
}
main()
{
	int c=0;
	for(int i=1;i<=10000;i++)
	{
		if(check2(i)) c++;
	}
	cout<<c;
}
