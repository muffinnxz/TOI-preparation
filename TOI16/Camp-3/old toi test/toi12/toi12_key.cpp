#include<bits/stdc++.h>
using namespace std;

string N, M, K;
int n, m;
bool dp[1001][1001], visited[1001][1001];

bool solve(int i, int j)
{
	int k = i + j;
	
	if(i == n && j == m) return true;
	
	if(visited[i][j]) return dp[i][j];
	visited[i][j] = true;
	
	if(i == n && K[k] == M[j]) return dp[i][j] = solve(i, j+1);
	if(j == m && K[k] == N[i]) return dp[i][j] = solve(i+1, j);
	
	if(K[k] == N[i] && K[k] == M[j]) return dp[i][j] =  (solve(i+1, j) || solve(i, j+1));
	else if(K[k] == N[i]) return dp[i][j] = solve(i+1, j);
	else if(K[k] == M[j]) return dp[i][j] = solve(i, j+1);
	
	return dp[i][j] = false;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	
	n = N.length();
	m = M.length();
	
	int t;
	cin >> t;
	
	while(t--)
	{
		cin >> K;	
		memset(visited, false, sizeof(visited));
		if(solve(0, 0)) cout << "Yes\n";
		else cout << "No\n";
	}
}
