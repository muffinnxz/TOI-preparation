#include<bits/stdc++.h>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin >> arr[i];
	
	if(n < 3)
	{
		cout << n;
		exit(0);
	}
	
	sort(arr.begin(), arr.end());
	
	int sum = arr[0], mx = 0;
	for(int i=1;i<n-1;i++)
	{
		sum += arr[i];
		int x = distance(arr.begin() + i - 1, lower_bound(arr.begin(), arr.end(), sum));
		mx = max(mx, x);
		sum -= arr[i-1];
	}
	
	cout << mx;
}
