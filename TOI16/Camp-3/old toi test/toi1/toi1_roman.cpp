#include<bits/stdc++.h>
using namespace std;

#define endll "\n"

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	int ans[] = {0,0,0,0,0};
	for(int i=1;i<=n;i++)
	{
		int num = i,j = 0;
		while(num != 0)
		{
			int tmp = num % 10;
			num /= 10;
			if(tmp <= 3) ans[j] += tmp;
			else if(tmp == 4) ans[j]++,ans[j+1]++;
			else if(tmp == 5) ans[j+1]++;
			else if(tmp <= 8) ans[j] += tmp - 5,ans[j+1]++;
			else ans[j]++,ans[j+2]++;
			j += 2;
		}
	}
	
	for(auto x : ans)
		cout<<x<<" ";
}
