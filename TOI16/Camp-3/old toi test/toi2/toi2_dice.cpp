#include<bits/stdc++.h>
using namespace std;

#define endll "\n"

int roll_dice(string s)
{
	int A=1,B=2,C=3,D=5,E=4,F=6;
	for(auto x:s)
	{
		int tmp;
		if(x == 'F')
		{
			tmp = A;
			A = D;
			D = F;
			F = B;
			B = tmp;
		}
		else if(x == 'B')
		{
			tmp = A;
			A = B;
			B = F;
			F = D;
			D = tmp;
		}
		else if(x == 'L')
		{
			tmp = A;
			A = E;
			E = F;
			F = C;
			C = tmp;
		}
		else if(x == 'R')
		{
			tmp = A;
			A = C;
			C = F;
			F = E;
			E = tmp;
		}
		else if(x == 'C')
		{
			tmp = B;
			B = E;
			E = D;
			D = C;
			C = tmp;
		}
		else
		{
			tmp = B;
			B = C;
			C = D;
			D = E;
			E = tmp;
		}
	}
	return B;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	string s;
	while(n--)
	{
		cin>>s;
		cout<<roll_dice(s)<<" ";
	}
}
