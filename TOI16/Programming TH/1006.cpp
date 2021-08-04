#include<bits/stdc++.h>
using namespace std;

int find(string s)
{
	char *p = &s[0];
	int A=1,B=2,C=3,D=5,E=4,F=6;
	int temp;
	while(*p!='\0')
	{
		if(*p=='F')
		{
			temp=A;
			A=D;
			D=F;
			F=B;
			B=temp;
		}
		else if(*p=='B')
		{
			temp=A;
			A=B;
			B=F;
			F=D;
			D=temp;
		}
		else if(*p=='L')
		{
			temp=A;
			A=E;
			E=F;
			F=C;
			C=temp;
		}
		else if(*p=='R')
		{
			temp=A;
			A=C;
			C=F;
			F=E;
			E=temp;
		}
		else if(*p=='C')
		{
			temp=B;
			B=E;
			E=D;
			D=C;
			C=temp;
		}
		else
		{
			temp=B;
			B=C;
			C=D;
			D=E;
			E=temp;
		}
		p++;
	}	
	
	return B;
}

main()
{
	int t;
	cin>>t;
	
	string temp;
	int ans[t];
	
	for(int r=0;r<t;r++)
	{
		cin>>temp;
		ans[r]=find(temp);
	}
	
	for(int r=0;r<t;r++)
		cout<<ans[r]<<" ";
}
