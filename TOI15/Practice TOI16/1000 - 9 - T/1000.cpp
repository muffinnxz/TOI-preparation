#include<iostream>
#include<vector>
using namespace std;

main()
{
	int m,n,i,j;
	cin>>n>>m;
	vector<char> wordchain[m];
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
		{
			char temp;
			cin>>temp;
			wordchain[i].push_back(temp);
		}
	int check=0;
	for(i=0;i<m-1;i++)
	{
		int c=0;
		for(j=0;j<n;j++)
		{
			if(wordchain[i][j]!=wordchain[i+1][j]) c++;
			if(c>2) break;
		}
		if(c>2)
		{
			for(j=0;j<n;j++)
				cout<<wordchain[i][j];
			check=1;
			break;
		}
	}
	if(check==0) 
	for(j=0;j<n;j++)
		cout<<wordchain[m-1][j];
}
