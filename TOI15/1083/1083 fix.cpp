#include<iostream>
#include<vector>
using namespace std;

main()
{
	int n,k;
	cin>>n;
	vector<int> stock,profit;
	profit.push_back(0);
	int temp;
	cin>>temp;
	stock.push_back(temp);
	for(int i=1;i<n;i++)
	{
		cin>>temp;
		stock.push_back(temp);
		if(stock[1]>stock[0]) profit.push_back(stock[1]-stock[0]+profit[i-1]);
		else profit.push_back(profit[i-1]);
		stock.erase(stock.begin());
	}
	cin>>k;
	for(int i=0;i<k;i++)
	{
		int a,b;
		cin>>a>>b;
		cout<<profit[b-1]-profit[a-1]<<endl;
	}
}
