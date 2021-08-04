#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n,h,q;
	cin>>n>>h>>q;
	
	vector<int> land(n,0);
	int i,j;
	int temp;
	for(i=0;i<h;i++)
	{
		scanf("%d",&temp);
		land[temp]=1;
	}
	//for(i=0;i<n;i++)
	//	cout<<land[i]<<" ";
	//cout<<endl;
	int k;
	for(i=0;i<q;i++)
	{
		scanf("%d",&k);
		vector<vector<bool> > con(n,vector<bool>(n,false));
		int x=0;
		for(j=0;j<n;j++)
		{
			if(land[j]==0) continue;
			if(j-k<0||j+k>=n) continue;
			if(land[j-k]==1&&!con[j][j-k]&&!con[j-k][j])
			{
				x++;
				//cout<<j<<" "<<j-k<<endl;
				con[j][j-k]=true;
				con[j-k][j]=true;
			}
			if(land[j+k]==1&&!con[j][j+k]&&!con[j+k][j])
			{
				x++;
				//cout<<j<<" "<<j+k<<endl;
				con[j][j+k]=true;
				con[j+k][j]=true;
			}
		}
		cout<<x<<" ";
	}
}

