#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > mout;
int maxTemp = 0;
int n;

void walk(int x,int y)
{
	if(x < 1 || x > n || y < 1 || y > n) return;
	if(mout[x][y] == 100) return;
	
	if(mout[x][y] > maxTemp) maxTemp = mout[x][y];
	
	if(mout[x+1][y] > mout[x][y]) walk(x+1,y);
	if(mout[x-1][y] > mout[x][y]) walk(x-1,y);
	if(mout[x][y+1] > mout[x][y]) walk(x,y+1);
	if(mout[x][y-1] > mout[x][y]) walk(x,y-1);
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	
	int x,y;
	cin>>x>>y;
	
	mout.push_back(vector<int> (n+2,100));
	for(int i=1;i<=n;i++)
	{
		mout.push_back(vector<int> (n+2,100));
		for(int j=1;j<=n;j++)
			cin>>mout[i][j];
	}
	mout.push_back(vector<int> (n+2,100));
	
	walk(y,x);
	
	cout<<maxTemp;
}
