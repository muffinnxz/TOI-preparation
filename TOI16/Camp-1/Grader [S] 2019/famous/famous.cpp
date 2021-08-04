#include<iostream>
#include<vector>
#include<list>
using namespace std;

int social()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<int> > vec(n,vector<int>(n, 0));
	list<int> famous;
	int x,y;
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		x--; y--;
		vec[x][y]=1;
		vec[y][x]=1;
	}
	for(int i=0;i<n;i++)
	{
		int fol=0;
		for(int j=0;j<n;j++)
			if(vec[i][j]==1) fol++;
		if(fol>=k) famous.push_back(i);
	}
	vector<bool> con(n,false);
	int ans=0;
	while(!famous.empty())
	{
		int temp=famous.front();
		famous.pop_front();
		for(int i=0;i<n;i++)
			if(vec[i][temp]==1&&!con[i])
			{
				ans++;
				con[i]=true;
			}
	}
	return ans;
}

int main()
{
	int c;
	cin>>c;
	int ans[c];
	for(int i=0;i<c;i++)
		ans[i]=social();
	for(int i=0;i<c;i++)
		cout<<ans[i]<<endl;
}
