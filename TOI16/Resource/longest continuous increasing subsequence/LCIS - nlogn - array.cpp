#include<bits/stdc++.h>
using namespace std;
 
int CeilIndex(int v[], int l, int r, int key) 
{ 
	while (r - l > 1) 
	{ 
		int m = l + (r - l) / 2; 
		if (v[m] >= key) r = m; 
		else l = m; 
	}
	return r; 
} 

int longestIncreSubseq(int v[],int n) 
{ 
	if (n == 0) return 1; 

	int tail[n];
	memset(tail,0,sizeof(tail)); 
	int length = 1; 

	tail[0] = v[0]; 
	for (int i=1;i<n;i++) 
	{ 
		if (v[i] < tail[0]) tail[0] = v[i]; 
		else if (v[i] > tail[length - 1]) tail[length++] = v[i]; 
		else tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i]; 
	}
	return length; 
} 

main() 
{ 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	int v[n];
	for(int i=0;i<n;i++)
		cin>>v[i];
		
	cout<<longestIncreSubseq(v,n);  
} 

