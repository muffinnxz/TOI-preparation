#include<bits/stdc++.h>
using namespace std;

#define endll "\n"

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	
	for(int i=0;i<(1<<n);i++)
	{
		int tmp = i;
		for(int j=0;j<n;j++)
		{
			cout << tmp % 2;
			tmp = tmp / 2;
		}
		cout << endll;
	}
}
