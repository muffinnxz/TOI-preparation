#include<bits/stdc++.h>
using namespace std;

int findpos(int f,char d,int x,int n)
{
	if(d == 'r') return (f+x) % n;
	if(f-x < 0) return (f-x) + n;
	return f-x;
}

void swap(int *a,int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	char cmd,d = 'r';
	int a,b,f = 0;
	
	for(int i=0;i<m;i++)
	{
		cin>>cmd;
		if(cmd == 'a') 
		{
			cin>>a>>b;
			a--; b--;
			swap(&arr[findpos(f,d,a,n)],&arr[findpos(f,d,b,n)]);
		}
		else if(cmd == 'b')
		{
			cin>>a>>b;
			a--;
			arr[findpos(f,d,a,n)] = b;
		}
		else if(cmd == 'c')
		{
			cin>>a;
			a--;
			f = findpos(f,d,a,n);
			if(d == 'r') d = 'l';
			else d = 'r';
		}
		else
		{
			cin>>a;
			a--;
			cout<<arr[findpos(f,d,a,n)]<<"\n";
		}
	}
}
