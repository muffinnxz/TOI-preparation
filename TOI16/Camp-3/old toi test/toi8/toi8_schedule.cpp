#include<bits/stdc++.h>
using namespace std;

#define endll "\n"

int N,M;
int workA[1005], workB[1005];

pair<int,int> dp[1005][1005];
bool visited[1005][1005];

pair<int,int> donejob(int i,int j)
{
	if(i == 0 && j == 0) return make_pair(1,0);	
	if(visited[i][j]) return dp[i][j];
	
	visited[i][j] = true;
	
	pair<int,int> A,B;
	
	if(i > 0)
	{
		A = donejob(i-1,j);
		if(A.second + workA[i] <= M) A.second += workA[i];
		else A.first++, A.second = workA[i];
	}
	
	if(j > 0)
	{
		B = donejob(i,j-1);
		if(B.second + workB[j] <= M) B.second += workB[j];
		else B.first++, B.second = workB[j];
	}
	
	if(i > 0 && j > 0) dp[i][j] = min(A,B);
	else if(i > 0) dp[i][j] = A;
	else dp[i][j] = B;
	
	return dp[i][j];
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>M>>N;
	for(int i=1;i<=N;i++)
		cin>>workA[i];
	for(int i=1;i<=N;i++)
		cin>>workB[i];
	
	memset(visited,false,sizeof(visited));
	
	pair<int,int> ans = donejob(N,N);
	cout<<ans.first<<endll<<ans.second;
}
