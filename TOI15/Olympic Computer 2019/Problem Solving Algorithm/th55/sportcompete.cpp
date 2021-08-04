#include<iostream>
using namespace std;

int fac(int a)
{
	int i,ans=1;
	for(i=1;i<=a;i++)
	{
		ans*=i;
	}
	return ans;
}
void section()
{
	
}

main()
{
	int k,a,b;
	
	cin>>k;
	cin>>a;
	cin>>b;
	
	int wal,kal;
	
	wal=k-a;
	kal=2*k-1-a-b;
	int cn=fac(kal)/(fac(kal-wal)*fac(wal));
	
	char x[cn][kal];
	char *pch=&x[0][0];
	
	int i,j;
	for(i=0;i<cn;i++)
	{
		for(j=0;j<kal;j++)
		{
			x[i][j]=
		}
	}
	
	
	
}
