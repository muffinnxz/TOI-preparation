#include <bits/stdc++.h>
using namespace std;

#define endll "\n"

int baseTwo(int n){
	int left,a[100];
	left=n;
	int i=0;
	while(left>0){
		a[i+1]=left%2;
		left=left/2;
		i++;
		a[0]= left==1? 0:1 ; 
	}
	for(int j=i;j>0;j--){
		cout<<a[j];
	}
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	for(int i=0;i<4;i++){
		baseTwo(i);
		cout << endll;
	}
}
