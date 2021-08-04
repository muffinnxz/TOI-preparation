#include<bits/stdc++.h>
using namespace std;

#define endll "\n"
const int div_prime = 1000000007;

int N,W;
int dp[1001][1001];
bool visited[1001][1001];
pair<int,int> item[1001];

int knapsack(int n,int w)
{
	if(n == 0 || w == 0) return 0;
	if(visited[n][w]) return dp[n][w];
	
	visited[n][w] = true;
	
	if(item[n].second > w) dp[n][w] = knapsack(n-1,w);
	else dp[n][w] = max(knapsack(n-1,w), item[n].first + knapsack(n-1,w-item[n].second));
	
	return dp[n][w];
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin>>T;
	
	while(T--)
	{
		cin>>N>>W;
	
		memset(visited,false,sizeof(visited));
		
		for(int i=1;i<=N;i++)
			cin>>item[i].first;
		for(int i=1;i<=N;i++)
			cin>>item[i].second;
			
		cout<<knapsack(N,W)<<endll;
	}
}
