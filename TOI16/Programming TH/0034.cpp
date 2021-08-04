#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;

main()
{
	int A,B,C;
	cin>>A>>B>>C;
	
	int a,b,c,d;
	bool flag=false;

	for(int i=1;i<=100;i++)
	{
		for(int j=-100;j<=100;j++)
		{
			for(int k=1;k<=100;k++)
			{
				for(int l=-100;l<=100;l++)
				{
					if(j*l!=C||i*k!=A) continue;
					a=i;
					b=j;
					c=k;
					d=l;
					if(((a*d)+(b*c))==B)
					{
						cout<<a<<" "<<b<<" "<<c<<" "<<d;
						flag=true;
						break;
					}
				}
				if(flag) break;
			}
			if(flag) break;
		}
		if(flag) break;
	}
	if(!flag) cout<<"No Solution";
}
