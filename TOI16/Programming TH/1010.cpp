#include<bits/stdc++.h>
#include<string>
using namespace std;

bool IsWord(int x,int y,int a,int b,char *p,char s[],int m)
{
	int len = strlen(s);
	for(int i=0;i<len;i++)
	{
		if(*(p+x*m+y) != s[i]) return false;
		x += a;
		y += b;
	}
	return true;
}

main()
{
	int n,m;
	cin>>n>>m;
	
	char word[n][m];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin>>word[i][j];
			word[i][j] = toupper(word[i][j]);
		}
	
	int q;
	cin>>q;
	
	char s[1000];
	for(int i=0;i<q;i++)
	{
		cin>>s;
		int len = strlen(s);
		for(int j=0;j<len;j++)
			s[j] = toupper(s[j]);
		
		for(int x=0;x<n;x++)
		{
			for(int y=0;y<m;y++)
			{
				bool isW = false;
				for(int a=-1;a<=1;a++)
					for(int b=-1;b<=1;b++)
					{
						if(a==0&&b==0) continue;
						if(IsWord(x,y,a,b,&word[0][0],s,m)) isW = true;
					}
				if(isW)
				{
					cout<<x<<" "<<y<<endl;
					x = n;
					y = m;
				}	
			}
		}
	}
}
