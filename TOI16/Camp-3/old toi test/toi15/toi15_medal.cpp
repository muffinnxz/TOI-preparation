#include<bits/stdc++.h>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	int A[n], B[n];
	for(int i=0;i<n;i++)
		cin >> A[i];
	for(int i=0;i<n;i++)
		cin >> B[i];
	
	sort(A, A+n);
	sort(B, B+n);
	reverse(B, B+n);
	
	int mn = INT_MAX, mx = 0;
	for(int i=0;i<n;i++)
	{
		mn = min(mn, A[i] + B[i]);
		mx = max(mx, A[i] + B[i]);
	}
	
	cout << mx - mn;
}
