#include<bits/stdc++.h>
using namespace std;

bool cmpWorm(pair<double,double> a,pair<double,double> b)
{
	return a.first / a.second > b.first / b.second;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	pair<double,double> worm[n];
	for(int i=0;i<n;i++)
		cin>>worm[i].first>>worm[i].second;
	
	sort(worm,worm+n,cmpWorm);
	
	double data = worm[0].first,cost = worm[0].second;
	double tmpdata = data,tmpcost = cost;
	for(int i=1;i<n;i++)
	{
		tmpdata += worm[i].first;
		tmpcost = max(tmpcost,worm[i].second);
		if(tmpdata/tmpcost <= data / cost) break;
		data = tmpdata;
		cost = tmpcost;
	}
	
	cout<<fixed<<setprecision(0);
	cout<<data<<" "<<cost;
}
