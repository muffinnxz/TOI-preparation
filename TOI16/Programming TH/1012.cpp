#include<bits/stdc++.h>
using namespace std;

int round_up(float n)
{
	if(n>(int)n) return n+1;
	return n;
}

main()
{
	int n;
	cin>>n;
	
	int use=0;
	int order[5]={0,0,0,0,0};
	
	int temp;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<5;j++)
		{
			cin>>temp;
			order[j]+=temp;
		}
	}
	
	int sum = order[0]*8 + order[1]*6 + order[2]*4 + order[3]*2 + order[4];
	cout<<round_up((float)sum/8);
}
