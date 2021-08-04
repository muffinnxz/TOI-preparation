#include<iostream>
#include<vector>
#include<list>
using namespace std;

main()
{
	int n,m;
	cin>>n>>m;
	vector<int> v[n];
	int i,j;
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			v[i].push_back(1);

	list<int> result;
	for(i=0;i<m;i++)
	{
		char c;
		int p;
		cin>>c>>p;
		p--;
		int count=0;
		if(c=='N')
		{
			for(j=0;j<n;j++)
			{
				if(v[j][p]==1) 
				{
					count++;
					v[j][p]=0;
				}
				else break;
			}
		}
		else if(c=='S')
		{
			for(j=n-1;j>=0;j--)
			{
				if(v[j][p]==1) 
				{
					count++;
					v[j][p]=0;
				}
				else break;
			}
		}
		else if(c=='W')
		{
			for(j=0;j<n;j++)
			{
				if(v[p][j]==1)
				{
					count++;
					v[p][j]=0;
				}
				else break;
			}
		}
		else 
		{
			for(j=n-1;j>=0;j--)
			{
				if(v[p][j]==1) 
				{
					count++;
					v[p][j]=0;
				}
				else break;
			}
		}
		result.push_back(count);
	}

	while(!result.empty())
	{
		printf("%d\n",result.front());
		result.pop_front();
	}
}
