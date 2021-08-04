#include<bits/stdc++.h>
using namespace std;

void move(char s,char t)
{
	cout<<s<<" to "<<t<<endl;
}

void hanoi(int n,char s,char c,char t)
{
	if(n==1)
	{
		move(s,t);
		return;
	}
	hanoi(n-1,s,t,c);
	move(s,t);
	hanoi(n-1,c,s,t);
}

main()
{
	hanoi(5,'A','B','C');
}
