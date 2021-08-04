#include<bits/stdc++.h>
using namespace std;

void rabinkarp(string s,string t,int q)
{
	int n = s.length();
	int m = t.length();
	int h = 1,d = 256;
	for(int i=0;i<m-1;i++)
		h = (h * d) % q;
	int sh = 0,th = 0;	
	for(int i=0;i<m;i++)
	{
		sh = (d * sh + s[i]) % q;
		th = (d * th + t[i]) % q;
	}
	for(int i=0;i<n-m;i++)
	{
		if(sh == th)
		{
			int j;
			for(j=0;j<m;j++)
				if(s[i+j] != t[j]) break;
			if(j == m) cout<<"Found At : "<<i<<endl;
		}
		sh = ((sh-s[i]*h)*d + s[i+m]) % q;
		if(sh < 0) sh += q;
	}
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s = "ABCSDQGASLKHVLASJKLJGLASLJHKNCLASLJASLDLQWUFIHWIUHJKDNVJK";
	string t = "ABC";
	int q = 101;
	rabinkarp(s,t,q);
}
