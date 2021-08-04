#include<iostream>
#include<vector>
#include<list>
using namespace std;

int main()
{
	int c;
	cin>>c;
	list<int>::iterator it;
	vector<list<int> > ans(c,list<int>());
	
	for(int g=0;g<c;g++)
	{
		int n,h,q;
		cin>>n>>h>>q;
		
		vector<int> land(n,0);
		list<int> avia;
		int i,j;
		int temp;
		for(i=0;i<h;i++)
		{
			scanf("%d",&temp);
			land[temp]=1;
			avia.push_back(temp);
		}
		avia.sort();
		int k;
		for(i=0;i<q;i++)
		{
			scanf("%d",&k);
			int x=0;
			for(it=avia.begin();it!=avia.end();it++)
			{
				if(*it+k>=n) break;
				if(land[*it+k]==1)
					x++;
			}
			ans[g].push_back(x);
		}
	}
	list<int>::iterator it2;
	for(int i=0;i<c;i++)
	{
		for(it2=ans[i].begin();it2!=ans[i].end();it2++)
			printf("%d ",*it2);
		printf("\n");
	}
}
