#include<iostream>
#include<math.h>
using namespace std;

int find_path(int n,int ice[])
{
	int i,j;
	int set[n];
	int con[n];
	for(i=0;i<n;i++)
	{
		set[i]=-1;
		con[i]=-1;
	}
	int temp=0;
	int temp2=0;
	for(i=0;i<n;i++)
	{
		cout<< ice[i]<<" "<<ice[i+1]<<" "<<temp<<" "<<temp2<<endl;
		
		if(abs(ice[i]-ice[i+1])>=1&&abs(ice[i]-ice[i+1])<=2) temp++;
		else 
		{
			for(j=0;j<=i;j++)
			{
				set[j]=temp2;
				con[j]=temp;
			}
			temp2++;
			temp=0;	
		}
	}
	
	for(j=0;j<n;j++)
		cout<<set[j]<<" ";
	cout<<endl;
	
	for(j=0;j<n;j++)
		cout<<con[j]<<" ";
	cout<<endl;
	
	return 0;
}

main()
{
	int c;
	cin>>c;
	for(int t=0;t<c;t++)
	{
		int n;
		cin>>n;
		
		int ice[n];
		for(int i=0;i<n;i++)
			cin>>ice[i];
		cout<<find_path(n,ice);
	}
}
