#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> arr(200001), bit(200001);

void update(int x, int delta)
{
	for(;x <= n; x += x&-x)
		bit[x] += delta;
}

int query(int x)
{
	int sum = 0;
	for(;x > 0; x -= x&-x)
		sum += bit[x];
	return sum;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	
	for(int i=1;i<=n;i++)
	{
		cin >> arr[i];
		update(i, 1);
	}
	
	/*for(int i=0;i<=n;i++)
		cout << bit[i] << " ";
	cout << "\n";*/
	
	for(int i=0;i<n;i++)
	{
		int idx;
		cin >> idx;
		
		int l = 1, r = n;
		while(l<r)
		{
			int mid = l + (r-l)/2;
			if(idx <= query(mid)) r = mid;
			else l = mid + 1;
		}
		cout << arr[l] << "\n";
		update(l, -1);
	}
}
