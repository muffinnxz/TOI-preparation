#include<bits/stdc++.h>
#include<iomanip>
#define endll "\n"
using namespace std;

int ch_to_ind(char x)
{
	if(x == 'X') return 0;
	else if(x == 'Y') return 27;
	return int(x - 'a' + 1);
}

char ind_to_ch(int x)
{
	if(x == 0) return 'X';
	else if(x == 27) return 'Y';
	return char('a' + x - 1);
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	vector<float> roadmap[28][28];
	
	char s, t;
	float x;
	
	while(n--)
	{
		cin>>s>>t>>x;
		roadmap[ch_to_ind(s)][ch_to_ind(t)].push_back(x);
		roadmap[ch_to_ind(t)][ch_to_ind(s)].push_back(x);
	}
	
	int u = 0, v = 0, i;
	bool visited[28];
	memset(visited, false, sizeof(visited));
	
	cout<<fixed;
	cout<<setprecision(1);
	
	float sum = 0;
	vector<pair<pair<int,int>, float> > path;
	while(true)
	{
		visited[u] = true;
		for(i=0;i<28;i++)
			if(!roadmap[u][i].empty() && !visited[i])
			{
				v = i;
				break;
			}
		if(i==28) break;
		
		sort(roadmap[u][v].begin(), roadmap[u][v].end());
		
		float med;
		int len = roadmap[u][v].size();
		
		if(len % 2 == 0) med = (roadmap[u][v][(len/2)- 1] + roadmap[u][v][len/2]) / 2.0;
		else med = roadmap[u][v][len/2];
		
		path.push_back(make_pair(make_pair(u, v), med));
		
		sum += med;
		u = v;
	}
	
	if(!visited[27]) cout<<"broken";
	else
	{
		for(auto x:path)
			cout << ind_to_ch(x.first.first) << " " << ind_to_ch(x.first.second) << " " << x.second << "\n";
		cout<<sum;
	}
}
