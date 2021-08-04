#include<bits/stdc++.h>
using namespace std;

bool cmpSet(int A[],int B[],int n)
{
	for(int i=0;i<n;i++)
		if(A[i] != B[i]) return false;
	return true;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	string w,s;
	cin>>w>>s;

	int setw[256] , sets[256];
	memset(setw,0,sizeof(setw));
	memset(sets,0,sizeof(sets));
	
	for(int i=0;i<n;i++)
		setw[w[i]]++;
	for(int i=0;i<n-1;i++)
		sets[s[i]]++;
	
	int ans = 0;
	for(int i=n-1;i<m;i++)
	{
		sets[s[i]]++;
		if(cmpSet(sets,setw,256)) ans++;
		sets[s[i-n+1]]--;
	}
	
	cout<<ans;
}
