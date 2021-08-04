#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define pii pair<int, ii>
int a[101][101];
bool mark[2520][101][101];
queue<pii> q;
pii mp(int a, int b, int c){
	return make_pair(a, make_pair(b, c));
}
int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			scanf("%d", &a[i][j]);
		}
	}
	q.push(mp(0, (N - 1)/2 + 1, 0));
	
	int od[6][2] = {{-1, 0}, {-1, 1}, {0, 1}, {0, -1}, {1, 0}, {1, 1}};
	int ed[6][2] = {{-1, 0}, {-1, -1}, {0, 1}, {0, -1}, {1, 0}, {1, -1}};
	
	while(!q.empty()){
		int stp = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		
		if(mark[stp % 2520][x][y]) continue;
		mark[stp % 2520][x][y] = true;
		if(x == (N - 1)/2 + 1 && y == M){
			printf("%d", stp);
			exit(0);
		}
		
		stp++;
		if(x % 2 == 0){
			for(int i = 0; i < 6; i++){
				int xx = x + ed[i][0];
				int yy = y + ed[i][1];
				if(xx < 1 || xx > N || yy < 1 || yy > M || a[xx][yy] == 0 || stp % a[xx][yy] != 0) continue;
				q.push(mp(stp, xx, yy));
			}
		}
		else{
			for(int i = 0; i < 6; i++){
				int xx = x + od[i][0];
				int yy = y + od[i][1];
				
				if(xx < 1 || xx > N || yy < 1 || yy > M || a[xx][yy] == 0 || stp % a[xx][yy] != 0) continue;
				q.push(mp(stp, xx, yy));
			}
		}
	}
}
