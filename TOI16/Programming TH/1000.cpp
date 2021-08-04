#include<iostream>
#include<vector>
using namespace std;

main()
{
	int m,n,i,j;
	cin>>n>>m;
	
	char wordchain[m][n+1];
	for(int i=0;i<m;i++)
		scanf("%s",&wordchain[i]);
	
	int temp;
	for(int i=0;i<m-1;i++)
	{
		temp=0;
		for(int j=0;j<n;j++)
		{
			if(wordchain[i][j]!=wordchain[i+1][j]) temp++;
			if(temp>2) break;
		}
		if(temp>2)
		{
			cout<<wordchain[i];
			break;	
		}
	}
	if(temp<=2) cout<<wordchain[m-1];
}
