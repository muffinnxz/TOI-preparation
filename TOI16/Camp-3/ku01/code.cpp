#include<bits/stdc++.h>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	int sum = 1, i = 1;
	while(sum < n)
	{
		sum += i*2+1;
		i++;
	}
	
	if(i%2 == n%2) cout << (i-1)*2;
	else cout << (i-1)*2 - 1;
}
