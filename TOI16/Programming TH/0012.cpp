#include<bits/stdc++.h>
#include<iomanip>
#define endll "\n"
#define PI 3.14159265358979323846
using namespace std;

main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string s;
	cin >> s;
	
	int l = s.length();
	for(int i=0;i<5;i++){
		for(int j=0;j<l*4+1;j++){
			int b=j/4, r=j%4;
			if (i==2 && r==2) 
				cout << s[b];
			else if((i<=2 && (r==2+i || r==2-i)) || (i>2 && (r==i%3+1 || r==3-i%3)))  
				((b%3==2 && j!=l*4) || (b%3==0 && j!=0 && i==2)) ? cout << '*' :  cout << '#';
			else cout << '.'; 
		}
		cout << endll;
	}
}
