#include<bits/stdc++.h>
#include<iomanip>
using namespace std;

int n, m;
int dir[8][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}, {-1,1}, {1,1}, {1,-1}, {-1,-1}};
double ans = DBL_MAX;

void solve(int x, int y, vector<vector<double> > v, double price, int b)
{
	if(b == n * m)
	{
		ans = min(ans, price);
		return;
	}
	
	vector<vector<double> > nv(v);
	for(int i=0;i<8;i++)
	{
		int xx = x + dir[i][0], yy = y + dir[i][1];
		if(xx < 0 || xx >= n || yy < 0 || yy >= m || nv[xx][yy] == 0) continue;
		nv[xx][yy] += 0.1 * nv[x][y];
	}
	
	nv[x][y] = 0;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(nv[i][j] != 0) solve(i, j, nv, price + nv[i][j], b+1);
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	vector<vector<double> > land(n, vector<double> (m, 0));
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> land[i][j];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			solve(i, j, land, land[i][j], 1);
	
	cout << fixed << setprecision(2);
	cout << ans;
}
