#include<iostream>
using namespace std;

main()
{
	int n;
	cin>>n;
	int pair[n][2];
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<2;j++)
			cin>>pair[i][j];
	
	int sum=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(pair[i][0]>pair[j][0]&&pair[i][1]<pair[j][1])
				sum+=pair[i][0]+pair[j][0];
		}
	}
	
	cout<<sum;
}
