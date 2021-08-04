#include<bits/stdc++.h>
using namespace std;

int calIndex(char n)
{
	if(n == 'X') return 0;
	if(n == 'Y') return 27;
	return n - 'a' + 1;
}

char printIndex(int n)
{
	if(n == 0) return 'X';
	else if(n == 27) return 'Y';
	return char('a' + n - 1);
}

float med(vector<int> v)
{
	int s = v.size();
	if(s % 2 == 1) return v[s/2];
	return (v[s/2-1] + v[s/2]) / 2.0;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	int g[28][28];
	for(int i=0;i<28;i++)
		for(int j=0;j<28;j++)
			g[i][j] = 0;
			
	vector<vector<int> > vect(1000);
	
	char node1,node2;
	int dist,tmp,u,v;
	for(int i=0;i<n;i++)
	{
		cin>>node1>>node2>>dist;
		u = calIndex(node1);
		v = calIndex(node2);
		if(u > v) tmp = u * 11 + v;
		else tmp = v * 11 + u;
		
		vect[tmp].push_back(dist);
		g[u][v] = 1;
		g[v][u] = 1;
	}
	
	bool visited[28];
	for(auto x : visited)
		x = false;
	
	u = 0;
	visited[u] = true;
	vector<pair<char,char> > ans_path;
	vector<float> ans_med;
	
	float total_cost = 0;
	while(u != 27)
	{
		v = -1;
		for(int i=0;i<28;i++)
			if(!visited[i] && g[u][i] == 1)
			{
				v = i;
				break;
			}
		if(v == -1) break;
		
		visited[v] = true;
		
		if(u > v) tmp = u * 11 + v;
		else tmp = v * 11 + u;
		
		sort(vect[tmp].begin(),vect[tmp].end());
		
		ans_path.push_back(make_pair(printIndex(u),printIndex(v)));
		ans_med.push_back(med(vect[tmp]));
		total_cost += med(vect[tmp]);
		
		u = v;
	}
	
	if(v == -1) cout<<"broken";
	else
	{
		int s = ans_path.size();
		for(int i=0;i<s;i++)
			printf("%c %c %.1f\n",ans_path[i].first,ans_path[i].second,ans_med[i]);
		printf("%.1f",total_cost);
	}
}
