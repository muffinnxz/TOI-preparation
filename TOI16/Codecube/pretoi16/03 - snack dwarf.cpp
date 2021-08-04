#include<bits/stdc++.h>
using namespace std;

#define endll '\n'

bool isAll(int arr[],int m)
{
	for(int i=1;i<=m;i++)
		if(arr[i] <= 0) return false;
	return true;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m,q;
	cin>>n>>m>>q;
	
	int snack[n];
	for(int i=0;i<n;i++)
		cin>>snack[i];
	
	int nearest_all[n];
	int appear[m+1];
	queue<int> last_all;
	memset(appear,0,sizeof(appear));
	
	set<int> is_already_in;
	
	for(int i=0;i<n;i++)
	{
		if(snack[i] > m)
		{
			if(is_already_in.size() == m) nearest_all[i] = last_all.front();
			else nearest_all[i] = -1;
		}
		else
		{
			appear[snack[i]]++;
			last_all.push(i);
			
			is_already_in.insert(snack[i]);
			
			if(is_already_in.size() == m)
			{
				while(appear[snack[last_all.front()]] > 1)
				{
					appear[snack[last_all.front()]]--;
					last_all.pop();
				}
				nearest_all[i] = last_all.front();
			}
			else nearest_all[i] = -1;
		}
	}

	int l,r;
	for(int i=0;i<q;i++)
	{
		cin>>l>>r;
		if(l-1 <= nearest_all[r-1]) cout<<"YES";
		else cout<<"NO";		
		cout<<endll;
	}
}
