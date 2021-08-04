#include<bits/stdc++.h>
using namespace std;

#define endll '\n'

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m,k;
	cin>>n>>m>>k;
	
	int seat[n][m];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>seat[i][j];
	
	int last_row_seat = 0;
	bool is_ans = false;
	
	for(int i=n-1;i>=0;i--)
	{
		int now_row_seat = 0;
		int sum = 0;
		
		for(int j=0;j<k-1;j++)
		{
			now_row_seat += seat[i][j];
			sum += seat[i][j];
		}
			
		for(int j=k-1;j<m;j++)
		{
			now_row_seat += seat[i][j];
			sum += seat[i][j];
			if(sum <= last_row_seat)
			{
				cout<<i+1;
				is_ans = true;
				break;
			}
			sum -= seat[i][j-k+1];
		}
		
		if(is_ans) break;
		last_row_seat += m - now_row_seat;
	}
	
}
