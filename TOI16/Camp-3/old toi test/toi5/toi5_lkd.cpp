#include<bits/stdc++.h>
#define endll "\n"
using namespace std;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	
	string s = "", ans = "", tmp;
	for(int i=0;i<n;i++){
		cin >> tmp;
		s += tmp;
	}
	
	int next[4][2] = {{0, 1}, {2, 3}, {1, 0}, {3, 2}}, 
	x=0, nowState=0, slen=s.length();
	for(int i=0;i<slen/2;i++){
		int code = s[i*2+1] - '0';
		
		if(nowState < 2) x = (x<<1) + code;
		else x = (x<<1) + !code;
		
		nowState = next[nowState][code];
		if((i+1)%8 == 0) ans=ans+char(x);
	}
	cout << ans;
}
