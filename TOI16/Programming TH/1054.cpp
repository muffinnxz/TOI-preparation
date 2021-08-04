#include<bits/stdc++.h>
using namespace std;

main()
{
	int n;
	scanf("%d",&n);
	
	vector<vector<int > > circle(n,vector<int> (3));
	for(int i=0;i<n;i++)
		for(int j=0;j<3;j++)
			cin>>circle[i][j];
	
	sort(circle.begin(),circle.end());

	int count = 0;
	int dx,dy,dr;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			dx = (circle[i][0] - circle[j][0]);
			dy = (circle[i][1] - circle[j][1]);
			if(abs(dx) > 21 && abs(dy) > 21) break;
			dr = (circle[i][2] + circle[j][2]);
			if(dx * dx + dy * dy < dr * dr)	count++;
		}
	}
	cout<<count;	
}
