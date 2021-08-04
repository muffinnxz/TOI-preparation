#include<iostream>
#include<math.h>
using namespace std;

int count_path(int arr[],int n)
{
	int temp=arr[n];
	int path=1;
	while(temp!=-1)
	{
		path+=abs(temp-n);
		n=temp;
		temp=arr[temp];
	}
	return path;
}

main()
{
	int n;
	cin>>n;
	
	int i,j;
	int ice[n];
	for(i=0;i<n;i++)
		cin>>ice[i];
		
	int con[n]={0};
	for(i=0;i<n;i++)
	{
		int temp=0;
		for(j=i;j<n-1;j++)
		{
			if(abs(ice[j]-ice[j+1])>=1&&abs(ice[j]-ice[j+1])<=2) temp++;
			else break;
		}
		if(temp==0) con[i]=-1;
		else con[i]=i+temp;
	}
	for(i=0;i<n;i++)
		cout<<con[i]<<" ";
	cout<<endl;

	int ans_max=0;
	int ans_locate=0;
	for(i=0;i<n-1;i++)
	{
		if(con[i]==-1)
		{
			int temp=con[i],temp2,l=-1;
			if(i!=0)
			{
				for(j=0;j<i;j++)
					if(con[j]==i)
					{
						temp2=con[j];
						l=j;
						con[j]--;
						if(con[j]==j) con[j]=-1;	
					}	
			}
			con[i]=i+1;
			for(i=0;i<n;i++)
				cout<<con[i]<<" ";
			cout<<endl;
			int max=0;
			for(j=0;j<n;j++) 
				if(count_path(con,j)>max) max=count_path(con,j);
			if(max>ans_max)
			{
				cout<<"A";
				ans_max=max;
				ans_locate=i;
			}
			con[i]=temp;
			if(l!=-1) con[l]=temp2;
		}
	}
	int ans_new=0;
	/*if(ans_locate==0) ans_new=ice[ans_locate+1]-2;
	else if(ans_locate==n-1) ans_new=ice[ans_locate-1]+2;
	else
	{
		if(ice[ans_locate-1]>ice[ans_locate+1]) ans_new=ice[ans_locate+1]-2;
		else 
		{
			cout<<ice[ans_locate-1];ans_new=ice[ans_locate-1]+2;
		}
	}*/
	cout<<endl<<ans_max<<" "<<ans_locate<<endl;
}
