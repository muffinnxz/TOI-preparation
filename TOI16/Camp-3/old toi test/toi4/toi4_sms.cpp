#include<bits/stdc++.h>
#define endll "\n"
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	string alph[9] = {"","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
	int bn[9] = {1,3,3,3,3,3,4,3,4};
	
	int n;
	cin>>n;
	
	int x, y, t;
	cin >> x >> t;
	
	x = x - 1;
	t = t - 1;
	y = x % 3;
	x = x / 3;
	
	char word[100];
	int wordEnd = 0;
	
	if(x != 0 || y != 0) word[wordEnd++] = alph[x*3+y][t%bn[x*3+y]];
	
	int a,b;
	for(int i=0;i<n-1;i++){
		cin >> a >> b >> t;
		x = x + b;
		y = y + a;
		t = t - 1;
		if(x == 0 && y == 0){
			wordEnd = wordEnd - t - 1;
			if(wordEnd < 0) wordEnd = 0;
		}
		else word[wordEnd++] = alph[x*3+y][t%bn[x*3+y]];
	}
	
	if(wordEnd == 0) cout<<"null";
	else {
		for(int i=0;i<wordEnd;i++)
			cout << word[i];
	}
}
