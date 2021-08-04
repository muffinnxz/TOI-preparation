#include<bits/stdc++.h>
using namespace std;

#define endll "\n"

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
		
	int s = 0,start = 0, end = 0, tmp = 0, mx = INT_MIN;
	for(int i=0;i<n;i++)
	{
		tmp += arr[i];
		
		if(tmp > mx)
		{
			start = s;
			end = i;
			mx = tmp;
		}
		if(tmp < 0)
		{
			s = i+1;
			tmp = 0;
		}
	}
	if(mx > 0)
	{
		for(int i=start;i<=end;i++)
			cout<<arr[i]<<" ";
		cout<<endll<<mx;	
	}
	else cout<<"Empty sequence";
}
