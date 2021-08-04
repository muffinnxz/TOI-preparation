#include<bits/stdc++.h>
using namespace std;

main()
{
	int n,k;
	cin>>n>>k;

	int item_price[n];
	int item_work[n]={0};
	int in_work;
	for(int i=0;i<n;i++)
	{
		cin>>item_price[i];
		for(int j=k-1;j>=0;j--)
		{
			cin>>in_work;
			item_work[i] += in_work * pow(2,j);
		}
	}
	
	int state_s = pow(2,k);
	int ans_price[state_s];
	
	ans_price[0]= 0;
	for(int i=1;i<state_s;i++)
		ans_price[i] = 9999999;
	
	for(int i=0;i<n;i++)
	{
		int new_price[state_s],new_item[state_s];
		for(int j=0;j<state_s;j++)
		{
			new_price[j] = ans_price[j] + item_price[i];
			new_item[j] = j|item_work[i];
		}
		for(int j=0;j<state_s;j++)
			if(new_price[j] < ans_price[new_item[j]]) ans_price[new_item[j]] = new_price[j];
	}
	cout<<ans_price[state_s-1];	
}
