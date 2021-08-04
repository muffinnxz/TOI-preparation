#include<iostream>
#include<vector>
#include<queue>
using namespace std;

main()
{
    int n,m;
    int i,j;
    cin>>n;
    int v[n+1][n+1];
    for(i=0;i<=n;i++)
    	for(j=0;j<=n;j++)
    		v[i][j]=0;
    for(i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v[a][b]=1;
        v[b][a]=1;
    }
    cin>>m;
    
    int countv[n+1];
    bool visited[n+1];
    for(i=0;i<n;i++)
        visited[i]=false;
    queue<int> q;
    visited[1]=true;
    countv[1]=1;
    q.push(1);
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        for(i=1;i<n+1;i++)
        {
            if(v[temp][i]==1&&!visited[i]) 
            {
                q.push(i);
                countv[i]=countv[temp]+1;
                visited[i]=true;
            }
        }
    }
    int count=0;
    for(i=1;i<n+1;i++)
    {
        if(countv[i]==m) count++;
    }
    cout<<count;
}
