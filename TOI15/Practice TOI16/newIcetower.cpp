#include<iostream>
using namespace std;

struct ret{
	int x;
	int y;
};

ret findp(int ice[],int n,int a)
{
	int i,j;
	int set[n];
	for(i=0;i<n;i++)
		set[i]=-1;
	int temp=0;
	int start=-1;
	for(i=0;i<n;i++)
	{
		if(set[i]!=-1) continue;
		if(i==n-1&&temp!=0&&start!=-1)
		{
			set[start]=temp+1;
			for(j=start+1;j<start+temp+1;j++)
				set[j]=0;
			set[start+temp]=temp+1;
			start=-1;
			temp=0;
			break;
		}
		if(1<=ice[i+1]-ice[i]&&ice[i+1]-ice[i]<=2)
		{
			if(temp==0) start=i;
			temp++;
		}
		else
		{
			if(start==-1) continue;
			set[start]=temp+1;
			for(j=start+1;j<start+temp;j++)
				set[j]=0;
			set[start+temp]=temp+1;
			start=-1;
			temp=0;
		}
	}
	
	int max=0;
	int locate=0;
	int r=0;
	for(i=0;i<n;i++)
	{
		if(set[i]==0) continue;
		else if(set[i]==-1)
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
				if(set[i-1]==-1&&set[i+1]==-1) 
				{
					if(1<ice[i+1]-ice[i-1]&&ice[i+1]-ice[i-1]<=4) r=3;
					else r=2;
				}
				else if(set[i-1]==-1&&set[i+1]!=-1)
				{
					if(1<ice[i+1]-ice[i-1]&&ice[i+1]-ice[i-1]<=4) r=set[i+1]+2;
					else r=set[i+1]+1;
				}
				else if(set[i-1]!=-1&&set[i+1]==-1)
				{
					if(1<ice[i+1]-ice[i-1]&&ice[i+1]-ice[i-1]<=4) r=set[i-1]+2;
					else r=set[i-1]+1;
				}
				else
				{
				    if(1<ice[i+1]-ice[i-1]&&ice[i+1]-ice[i-1]<=4) r=set[i-1]+set[i+1]+1;
					else if(set[i-1]>set[i+1]) r=set[i-1]+1;
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
			    if(set[i-1]>0&&set[i+1]>0) 
			    {
			        if(set[i]>set[i-1]) r=set[i];
			        else r=set[i-1]+1;
			    }
			    else r=set[i];
			}
		}
		
		if(a==1&&r>max)
		{
			max=r;
			locate=i;
		}
		else if(a==2&&r>=max)
		{
			max=r;
			locate=i;
		}
	}
	//cout<<max<<" "<<locate<<endl;
	
	ret re;
	re.x=max;
	re.y=locate;
	return re;
}
void revs(int arr[],int a,int b)
{
	while(a<b)
	{
		int temp=arr[a];
		arr[a]=arr[b];
		arr[b]=temp;
		a++;
		b--;
	}
}
int main()
{
	int c;
	cin>>c;
	
	int ans[c][2];
	for(int i=0;i<c;i++)
	{
		int n;
		cin>>n;
		
		int temp[n];
		for(int j=0;j<n;j++)
			cin>>temp[j];
		ret re1,re2;
		re1=findp(temp,n,1);
		revs(temp,0,n-1);
		re2=findp(temp,n,2);
		//cout<<re1.x<<" "<<re1.y<<endl;
		//cout<<re2.x<<" "<<n-1-re2.y<<endl;
		if(re1.x>re2.x)
		{
			ans[i][0]=re1.x;
			ans[i][1]=re1.y;
		} 
		else if(re1.x<re2.x)
		{
			ans[i][0]=re2.x;
			ans[i][1]=n-1-re2.y;
		}
		else if(re1.y<n-1-re2.y)
		{
			ans[i][0]=re1.x;
			ans[i][1]=re1.y;
		}
		else
		{
			ans[i][0]=re2.x;
			ans[i][1]=n-1-re2.y;
		}
	}
	for(int i=0;i<c;i++)
	    cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
	return 0;
}
