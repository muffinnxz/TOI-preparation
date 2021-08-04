#include<iostream>
#include<math.h>
using namespace std;

struct ret{
	int x;
	int y;
};

ret findp(int ice[],int n)
{
	int set[n],set_s[n];
	for(int i=0;i<n;i++)
	{
		set[i]=-1;
		set_s[i]=-1;	
	}
	int i=0;
	int s=-1;
	int temp=0, c=0;
	for(i=0;i<n-1;i++)
	{
		if(1<=ice[i]-ice[i+1]&&ice[i]-ice[i+1]<=2)
		{
			if(temp==0) s=i;
			temp++;
		}
		else
		{
			if(s==-1) continue;
			set[s]=temp+1;
			set_s[s]=c;
			for(int j=s+1;j<s+temp;j++)
			{
				set[j]=0;
				set_s[j]=c;
			}
			set[s+temp]=temp+1;
			set_s[s+temp]=c;
			temp=0;
			s=-1;
			c++;
		}	
	}
	
	for(i=0;i<n;i++)
		cout<<set[i]<<" ";
	cout<<endl;
	for(i=0;i<n;i++)
		cout<<set_s[i]<<" ";
	cout<<endl;
	
	int max=0;
	int locate;
	for(i=0;i<n;i++)
	{
		if(set[i]==0) continue;
		int r=0;
		if(set[i]==-1)
		{
			if(i==0)
			{
				if(set[i+1]==-1) r=2;
				else r=set[i+1]+1;
			}
			else if(i==n-1)
			{
				if(set[i-1]==-1) r=2;
				else r=set[i-1]+1;
			}
			else
			{
				int d=abs(ice[i-1]-ice[i+1]);
				if(1<d&&d<=4) 
				{
					if(set_s[i-1]!=-1&&set_s[i+1]!=-1) r=set[i-1]+set[i+1]+1;
					else if(set_s[i-1]==-1&&set_s[i+1]!=-1) r=set[i+1]+2;
					else if(set_s[i-1]!=-1&&set_s[i+1]==-1) r=set[i-1]+2;
					else r=3;
				}
				else
				{
					if(set[i-1]>set[i+1]) r=set[i-1]+1;
					else r=set[i+1]+1;
				}
			}
		}
		else
		{
			if(i==0) r=set[i];
			else if(i==n-1) r=set[i];
			else
			{
				if((set_s[i-1]==-1||set_s[i+1]==-1) && (set_s[i-1]!=-1||set_s[i+1]!=-1)) r=set[i];
				else if(set[i]>set[i+1]) r=set[i];
				else r=set[i+1]+1;
			}
		}
		if(r>max) 
		{
			max=r;
			locate=i;
		}
	}
	ret re;
	re.x=max;
	re.y=locate;
	return re;
}
void revarr(int arr[],int a,int b)
{
	while(a>b)
	{
		int temp=arr[a];
		arr[a]=arr[b];
		arr[b]=temp;
		a++;
		b--;
	}
}
main()
{
	int c;
	cin>>c;
	int ans[c][2];
	for(int i=0;i<c;i++)
	{
		int n;
		cin>>n;
		int ice[n];
		for(int j=0;j<n;j++)
			cin>>ice[j];
		ret re1,re2;
		re1=findp(ice,n);
		int a=0,b=n-1;
		while(a<b)
		{
			int temp=ice[a];
			ice[a]=ice[b];
			ice[b]=temp;
			a++;
			b--;
		}
		for(int j=0;j<n;j++)
			cout<<ice[j]<<" ";
		cout<<endl;
		re2=findp(ice,n);
		cout<<"-> "<<re1.x<<" "<<re1.y<<endl;
		cout<<"-> "<<re2.x<<" "<<re2.y<<endl;
		if(re1.x>re2.x)
		{
			ans[i][0]=re1.x;
			ans[i][1]=re1.y;
		}
		else if(re1.x<re2.x)
		{
			ans[i][0]=re2.x;
			ans[i][1]=(n-re2.y);
		}
		else
		{
			if(re1.y<(n-re2.y))
			{
				ans[i][0]=re1.x;
				ans[i][1]=re1.y;
			}
			else
			{
				ans[i][0]=re2.x;
				ans[i][1]=(n-re2.y);
			}
		}
	}
	for(int i=0;i<c;i++)
		cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
}
