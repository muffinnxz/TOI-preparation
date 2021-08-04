#include<bits/stdc++.h>
using namespace std;

int n,p;
int a[1005],b[1005];

pair<int,int> dp[1005][1005];
bool visited[1005][1005];

pair<int,int> donejob(int i,int j)
{	
	if(i == 0 && j == 0) return make_pair(1,0); 
	
	if(visited[i][j]) return dp[i][j];
	
	pair<int,int> A,B;
	
	if(i > 0)
	{
		A = donejob(i-1,j); 
		if(A.second + a[i] <= p) A.second += a[i];
		else A.second = a[i],A.first++;
	}
	
	if(j > 0)
	{
		B = donejob(i,j-1);
		if(B.second + b[j] <= p) B.second += b[j];
		else B.second = b[j],B.first++;
	}
	
	if(i > 0 && j > 0) dp[i][j] = min(A,B);
	else if(i > 0) dp[i][j] = A;
	else dp[i][j] = B;
	
	visited[i][j] = true;
	return dp[i][j];
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>p>>n;
	
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	
	memset(visited,false,sizeof(visited));
	
	visited[0][0] = true;
	dp[0][0] = make_pair(1,0);
	
	pair<int,int> tmp = donejob(n,n);
	cout<<tmp.first<<"\n"<<tmp.second;
}
