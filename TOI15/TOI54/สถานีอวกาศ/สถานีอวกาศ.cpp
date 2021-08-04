#include<iostream>
#include<list>
#include<math.h>
using namespace std;

list<unsigned long long int> pos;

void showpos(int x,int n)
{
	int v,i;
	list<unsigned long long int> temp;
	unsigned long long int sum=0;
	for(i=0;i<n;i++)
	{
		v=(x&(1<<i))!=0;
		if(v==1)
		{
			temp.push_back(1);
		}
		else
		{
			temp.push_back(2);
		}
	}
	for(i=0;i<n;i++)
	{
		sum+=temp.back()*pow(10,i);
		temp.pop_back();
	}
	pos.push_back(sum);
}

main()
{
	int d;
	cin>>d;
	
	int alln=pow(2,d);
	int i;
	for(i=0;i<alln;i++)
	{
		showpos(i,d);
	}
	
	list<unsigned long long int>::iterator it,it2;
	for(it=pos.begin();it!=pos.end();it++)
	{
		for(it2=it;it2!=pos.end();it2++)
		{
			if(*it>*it2) 
			{
				int temp=*it-*it2;
				int one=0,nine=0;
				while(temp!=0)
				{
					if(temp%10==1) one++;
					else if(temp%10==9) nine++;
					temp/=10;
				}
				if(one==1&&nine==0) 
				{
					int a=*it,b=*it2;
					while(a!=0)
					{
						if(a%10==2) cout<<"0";
						else cout<<"1";
						a/=10;
					}
					cout<<" ";
					while(b!=0)
					{
						if(b%10==2) cout<<"0";
						else cout<<"1";
						b/=10;
					}
					cout<<endl;
				}
			}
		}
	}
}
