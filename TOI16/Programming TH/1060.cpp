#include<bits/stdc++.h>
using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	
	int N;
	cin>>N;
	
	int input[N][2];
	int n = 0,m =0;
	for(int i=0;i<N;i++)
	{
		cin>>input[i][0]>>input[i][1];
		if(input[i][0] + input[i][1] * 2 > m) m = input[i][0] + input[i][1] * 2;
		if(input[i][1] > n) n = input[i][1];
	}
	
	m--;
	char pic[n][m];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			pic[i][j] = '.';
			
	int S,H;
	for(int i=0;i<N;i++)
	{
		S = input[i][0];
		H = input[i][1];
		S--;
		int l = H * 2;
		for(int i=n-1;i>=n-H;i--)
		{
			for(int j=S;j<S+l;j++)
			{
				if(pic[i][j] == 'X') continue;
				if(j==S) 
				{
					if(pic[i][j] == '\\') pic[i][j] = 'v';
					else pic[i][j] = '/';
				}
				else if(j==S+l-1)
				{
					if(pic[i][j] == '/') pic[i][j] = 'v';
					else pic[i][j] = '\\';
				}
				else pic[i][j] = 'X'; 
			}
			S++;
			l-=2;
		}
	}
	
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout<<pic[i][j];
		cout<<endl;
	}
	
}
