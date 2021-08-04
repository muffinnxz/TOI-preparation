#include<iostream>
using namespace std;
main()
{
	int n;
	cin>>n;
	int i;
	int tc[5]={0};
	for(i=0;i<n;i++)
	{
		int temp=i+1;
		int j;
		int c[5]={0};
		int f[2]={0};
		for(j=0;j<temp;j++)
		{
			c[0]++;
			int k;
			for(k=0;k<4;k++)
			{
				if(k%2==0)
				{
					if(c[k]>3)
					{
						c[k]=0;
						if(k==0) f[0]++;
						else f[1]++;
						c[k+1]++;	
					}
				}
				else
				{
					if(c[k]>1)
					{
						c[k-1]=0;
						c[k]=0;
						c[k+1]++;	
					}
				}
			}
		}
		for(j=0;j<5;j++)
		{
			cout<<c[j]<<" ";
			tc[j]+=c[j];
		}
		cout<<endl;	
	}
	for(i=0;i<5;i++)
		cout<<tc[i]<<" ";
}
