#include<iostream>
#include<vector>
#include<list>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;

list<int> temp;

void allpos(int x,int n)
{
	int i,v;
	for(i=0;i<n;i++)
	{
		v=(x&(1<<i))!=0;
		if(v==1)
			temp.push_back(1);
		else 
			temp.push_back(0);
	}
}

main()
{
	int d;
	cin>>d;
	
	int ss=pow(2,d);
	vector<int> v[ss];
	int i,j,k;
	for(i=0;i<ss;i++)
	{
		allpos(i,d);
		while(!temp.empty())
		{
			v[i].push_back(temp.front());
			temp.pop_front();
		}
	}
	sort(&v[1],&v[ss-1]);
	for(i=0;i<ss;i++)
	{
		for(j=i+1;j<ss;j++)
		{
			int a=0;
			for(k=0;k<d;k++)
			{
				if(v[i][k]!=v[j][k]) a++;
				if(a>1) break;  
			}
			if(a<=1)
			{
				for(k=0;k<d;k++)
					cout<<v[i][k];	
				cout<<" ";
				for(k=0;k<d;k++)
					cout<<v[j][k];
				cout<<endl;	
			}
		}
	}
}
