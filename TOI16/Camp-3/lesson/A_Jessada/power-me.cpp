#include<bits/stdc++.h>
using namespace std;

int findR(int n, int k)
{
	int pat[1001];
	memset(pat,0,sizeof(pat));
	
	int i = 1, product = 1, first_loop = -1;
	for(int j=0;j<k;j++)
	{
		product = (product * n) % 1000;
		if(pat[product] == 0) pat[product] = i++;
		else 
		{
			first_loop = pat[product];
			break;
		}
	}
	
	int AnsTh;
	
	if(first_loop == -1) AnsTh = i-1;
	else 
	{
		int loop_size = i - first_loop;
		AnsTh = first_loop + k - (k/loop_size) * loop_size;
		if(AnsTh == 0) AnsTh = loop_size;
	}
	
	if(AnsTh == 0) return 1;
	else
	{
		for(int i=0;i<1001;i++)
			if(pat[i] == AnsTh) return i;	
	}
}

main()
{
	int t;
	cin>>t;
	
	int n, k;
	while(t--)
	{
		cin>>n>>k;
		cout<<findR(n, k)<<endl;
	}
}
