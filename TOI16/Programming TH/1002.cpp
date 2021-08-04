#include<iostream>
using namespace std;

main()
{
	int n;
	cin>>n;
	int ans[5]={0};
	for(int l=1;l<=n;l++)
	{
		int k=l; 
		int i=0;
		int count[5]={0};
		while(k!=0)
		{
			int temp=k%10;
			k/=10;
			if(temp<=3) count[i]+=temp;
			else if(temp==4)
			{
				count[i]++;
				count[i+1]++;
			}
			else if(temp==5) count[i+1]++;
			else if(temp>5&&temp<9)
			{
				count[i]+=temp%5;
				count[i+1]++;
			}
			else
			{
				count[i]++;
				count[i+2]++;
			}
			i+=2;
		}
		for(i=0;i<5;i++)
			ans[i]+=count[i];
	}
	for(int i=0;i<5;i++)
		cout<<ans[i]<<" ";
}
