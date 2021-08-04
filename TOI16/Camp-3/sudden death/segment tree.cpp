#include<bits/stdc++.h>
using namespace std;

int arr[100001], tree[200002], n;

void build(int idx_node, int start, int endd)
{
	if(start == endd) tree[idx_node] = arr[start];
	else
	{
		int mid = start + (endd-start)/2;
		build(2*idx_node, start, mid);
		build(2*idx_node+1, mid+1, endd);
		tree[idx_node] = tree[2*idx_node] + tree[2*idx_node+1];
	}
}

void update(int idx_node, int start, int endd, int idx, int val)
{
	if(start == endd)
	{
		tree[idx_node] = val;
		arr[idx] = val;
	}
	else
	{
		int mid = start + (endd-start)/2;
		if(start <= idx && idx <= mid) update(2*idx_node,start,mid,idx,val);
		else update(2*idx_node+1,mid+1,endd,idx,val);
		tree[idx_node] = tree[2*idx_node] + tree[2*idx_node+1];
	}
}

int query(int idx_node, int start, int endd, int l, int r)
{
	if(r < start || endd < l) return 0;
	if(l <= start && endd <= r) return tree[idx_node];
	int mid = start + (endd-start)/2;
	return query(2*idx_node,start,mid,l,r) + query(2*idx_node+1,mid+1,endd,l,r);
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> n;

	for(int i=1;i<=n;i++)
	{
		cin >> arr[i];
		arr[i] = arr[i] % 2;	
	}	
	
	build(1,1,n);
	
	for(int i=1;i<=2*n;i++)
		cout << tree[i] << " ";
	cout << "\n";
	
	int q;
	cin >> q;
	
	while(q--)
	{
		int cmd, x, y;
		cin >> cmd >> x >> y;
		if(cmd == 0) update(1, 1, n, x, y%2);
		else if(cmd == 1) cout << query(1, 1, n, x, y) << "\n";
		else cout << (y-x+1) - query(1, 1, n, x, y) << "\n";
	}
	
}
