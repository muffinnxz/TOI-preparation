#include<bits/stdc++.h>
#define endll "\n"
using namespace std;
bool cmp(pair<long long int,long long int> a, pair<long long int,long long int> b)
{
	return (a.second < b.second) || (a.second == b.second && a.first < b.second);
}
main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	pair<long long int, long long int> box[n];
	
	long long int minh = LLONG_MAX;
	for(int i=0;i<n;i++)
	{
		cin>>box[i].first;
		minh = min(minh, box[i].first);
	}
	
	for(int i=0;i<n;i++)
		cin>>box[i].second;
	
	sort(box, box+n, cmp);
	
	long long int ml = 0, mr = 0;
	for(int i=1;i<n;i++)
		mr += box[i].second - box[0].second;
	
	long long int P = box[0].second, M = mr;
	for(int i=1;i<n && box[i].second <= minh;i++)
	{
		mr -= (n-i) * (box[i].second - box[i-1].second);
		if(box[i].second == box[i-1].second) ml += box[i-1].first;	
		else
		{
			ml += (box[i-1].second + (box[i-1].first - box[i].second));
			ml -= (i-1) * (box[i].second - box[i-1].second);
			if(ml + mr < M)
			{
				M = ml + mr;
				P = box[i].second;
			}
		}
	}
	cout<<P<<" "<<M;
}
