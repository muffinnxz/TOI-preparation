#include<bits/stdc++.h>
using namespace std;

#define endll "\n"

int n;
pair<int,int> arr[100001], temp[100001];

int merge(int l,int mid, int r)
{
	int i=l, j=mid, k=l;
	int sum=0;
	while(i<=mid-1 && j<=r)
	{
		if(arr[i].first <= arr[j].first) temp[k++] = arr[i++];
		else 
		{
			sum += (mid-i);
			temp[k++] = arr[j++];	
		}	
	}
	
	while(i<=mid-1) temp[k++] = arr[i++];
	while(j<=r) temp[k++] = arr[j++];
	
	for(int p=l;p<=r;p++)
		arr[p] = temp[p];
	
	return sum;	
}

int mergesort(int l,int r)
{
	int sum = 0;
	if(r > l)
	{
		int mid = (l+r)/2;
		
		sum += mergesort(l,mid);
		sum += mergesort(mid+1,r);
		
		sum += merge(l,mid+1,r);
	}
	cout<<l<<" "<<r<<" "<<sum<<endll;
	return sum;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;
	
	for(int i=0;i<n;i++)
		cin>>arr[i].first>>arr[i].second;
	
	for(int i=0;i<n;i++)
		cout<<arr[i].first<<" "<<arr[i].second<<endll;
		
	cout<<mergesort(0,n-1);
}
