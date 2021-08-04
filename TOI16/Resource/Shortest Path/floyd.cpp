#include<bits/stdc++.h>
using namespace std;

#define INF 999999

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int V = 4;
	
	int graph[4][4] = {{0,5,INF,10},
					   {INF,0,3,INF},
					   {INF,INF,0,1},
					   {INF,INF,INF,0}};
	
	for(int k=0;k<V;k++)
		for(int i=0;i<V;i++)
			for(int j=0;j<V;j++)
				if(graph[i][k] + graph[k][j] < graph[i][j]) graph[i][j] = graph[i][k] + graph[k][j];
				
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
			cout<<graph[i][j]<<" ";
		cout<<endl;
	}	
}
