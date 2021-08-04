#include<iostream>
#include<vector>
#include<list>
using namespace std;

main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int i,j;
	vector<int> army,status;
	list<int> result;
	for(i=0;i<n;i++)
	{
		int temp;
		cin>>temp;
		army.push_back(temp);
		status.push_back(-1);
	}
	for(i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--;b--;
		bool k=true;
		while(k)
		{
			int temp=status[a];
			if(temp==-1) break;
			else a=status[a];
		}	
		while(k)
		{
			int temp=status[b];
			if(temp==-1) break;
			else b=status[b];
		}
		if(a==b) result.push_back(-1);
		else if(army[a]==army[b])
		{
			if(a<b)
			{
				result.push_back(a+1);
				army[a]+=army[b]/2;	
				status[b]=a;
			}
			else 
			{
				result.push_back(b+1);
				army[b]+=army[a]/2;
				status[a]=b;
			}
		}
		else if(army[a]<army[b])
		{
			result.push_back(b+1);
			army[b]+=army[a]/2;
			status[a]=b;
		}
		else
		{
			result.push_back(a+1);
			army[a]+=army[b]/2;	
			status[b]=a;
		}
	}
	while(!result.empty())
	{
		printf("%d\n",result.front());
		result.pop_front();
	}
}
