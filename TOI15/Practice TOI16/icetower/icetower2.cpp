#include<iostream>
#include<math.h>
using namespace std;

struct arrx{
	int x;
	int y;
};

arrx cal(int n,int ice[])
{
	int i,j;
		
	int set[n];
	for(i=0;i<n;i++)
		set[i]=0;
	int max=0;
	int x=0,y=0;
	for(i=0;i<n;i++)
	{
		int temp=1;
		for(j=i;j<n-1;j++)
		{
			if(abs(ice[j]-ice[j+1])>=1&&abs(ice[j]-ice[j+1])<=2) temp++;
			else break;
		}
		if(temp>max) max=temp;
		if(temp>set[i]) set[i]=temp;
		if(temp>set[i+j]) set[i+j]=temp;
		//for(j=i;j<i+temp;j++)
		//	if(temp>set[j]) set[j]=temp;
	}

	for(i=0;i<n;i++)
	{
		int newrec;
		if(i==0) newrec=set[i+1]+1;
		else if(i==n-1) newrec=set[i-1]+1;
		else
		{
			if(abs(ice[i-1]-ice[i+1])==4)
			{
				if(set[i-1]==1||set[i+1]==1) newrec=set[i-1]+set[i+1]+1;
				else newrec=set[i-1]+set[i+1];
			} 
			else if(set[i-1]>set[i+1]) newrec=set[i-1]+1;
			else if(set[i-1]<set[i+1]) newrec=set[i+1]+1;
			else newrec=set[i];
		}
		if(newrec>max)
		{
			max=newrec;
			x=i;
			if(i==0) y=ice[i+1]+2;
			else if(i==n-1) y=ice[i-1]+2;
			else
			{
				if(abs(ice[i-1]-ice[i+1])==4) y=(ice[i-1]+ice[i+1])/2;
				else if(set[i-1]>set[i+1]) y=ice[i-1]+2;
				else if(set[i-1]<set[i+1]) y=ice[i+1]+2;
				else y=ice[i];
			}
		}
	}
	arrx temp;
	temp.x=x; temp.y=y;
	return temp;
}
main()
{
	int n;
	scanf("%d",&n);
	int ans[n][2];
	int i;
	for(i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		int arr[a];
		for(int j=0;j<a;j++)
			scanf("%d",&arr[j]);
		arrx temp=cal(a,arr);
		ans[i][0]=temp.x;
		ans[i][1]=temp.y;
	}
	for(i=0;i<n;i++)
		cout<<ans[i][1]<<" "<<ans[i][0]<<endl;
}
