#include<bits/stdc++.h>
#include<vector>
using namespace std;

int floadfill(int *v ,int x,int y,int prevc, int newc,int n)
{
	if(x<0||y<0||x>=n||y>=n) return 0;
	if(*(v+x*n+y)!=prevc) return 0;
	
	int ans=0;
	if(*(v+x*n+y)!=0)
	{
		ans++;
		*(v+x*n+y)=newc;
	}
	else return 0;
	
	ans+=floadfill(v,x+1,y,prevc,newc,n);
	ans+=floadfill(v,x-1,y,prevc,newc,n);
	ans+=floadfill(v,x,y+1,prevc,newc,n);
	ans+=floadfill(v,x,y-1,prevc,newc,n);
	
	return ans;
}

bool check(int *v,int *v2,int x,int y,int newc,int n)
{
	if(*(v+x*n+y)==0) return false;
	
	int temp=floadfill(v,x,y,*(v+x*n+y),newc,n);
	
	if(temp!=3) return false;
	
	if(*(v2+(x+1)*n+y)==*(v2+x*n+y)&&*(v2+x*n+(y+1))==*(v2+x*n+y)) return true;
	if(*(v2+(x-1)*n+y)==*(v2+x*n+y)&&*(v2+x*n+(y+1))==*(v2+x*n+y)) return true;
	if(*(v2+(x+1)*n+y)==*(v2+x*n+y)&&*(v2+x*n+(y-1))==*(v2+x*n+y)) return true;
	if(*(v2+(x-1)*n+y)==*(v2+x*n+y)&&*(v2+x*n+(y-1))==*(v2+x*n+y)) return true;
	
	if(*(v2+(x+1)*n+(y+1))==*(v2+x*n+y)&&*(v2+x*n+(y+1))==*(v2+x*n+y)) return true;
	if(*(v2+(x-1)*n+(y+1))==*(v2+x*n+y)&&*(v2+x*n+(y+1))==*(v2+x*n+y)) return true;
	
	if(*(v2+(x+1)*n+(y-1))==*(v2+x*n+y)&&*(v2+x*n+(y-1))==*(v2+x*n+y)) return true;
	if(*(v2+(x-1)*n+(y-1))==*(v2+x*n+y)&&*(v2+x*n+(y-1))==*(v2+x*n+y)) return true;
	
	if(*(v2+(x+1)*n+(y-1))==*(v2+x*n+y)&&*(v2+(x+1)*n+y)==*(v2+x*n+y)) return true;
	if(*(v2+(x+1)*n+(y+1))==*(v2+x*n+y)&&*(v2+(x+1)*n+y)==*(v2+x*n+y)) return true;
	
	if(*(v2+(x-1)*n+(y-1))==*(v2+x*n+y)&&*(v2+(x-1)*n+y)==*(v2+x*n+y)) return true;
	if(*(v2+(x-1)*n+(y+1))==*(v2+x*n+y)&&*(v2+(x-1)*n+y)==*(v2+x*n+y)) return true;
	
	return false;
}

main()
{
	int n;
	cin>>n;
	int mat[n][n];
	int mat2[n][n];
	int *p,*p2;
	p=&mat[0][0];
	p2=&mat2[0][0];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cin>>mat[i][j];
			mat2[i][j]=mat[i][j];
		}
		
	int c=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(check(p,p2,i,j,0,n)) c++;	
	
	cout<<c;
	
}
