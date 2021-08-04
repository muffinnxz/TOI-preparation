#include<bits/stdc++.h>
using namespace std;

bool isValid(int col[],int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(col[i] == col[j] || abs(col[i]-col[j]) == abs(i-j)) return false;
	return true;
}

void printcol(int col[],int n)
{
	cout<<"[";
	for(int i=0;i<n;i++)
		cout<<col[i]+1<<" ";
	cout<<"]"<<" ";
}

void placequeen(int col[],int m,int n)
{
	if(m == n) 
	{
		printcol(col,n);
		return;
	}
	for(int i=0;i<n;i++)
	{
		col[m] = i;
		if(isValid(col,m+1)) placequeen(col,m+1,n);
	}
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	cin>>T;
	
	int n;
	while(T--)
	{
		cin>>n;
		if(n == 2 || n == 3) cout<<-1<<endl;
		else
		{
			int col[n];
			for(int i=0;i<n;i++) col[i] = 0;
			placequeen(col,0,n);
			cout<<endl;	
		}
	}
	
}
