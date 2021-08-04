#include<bits/stdc++.h>
using namespace std;

bool checkpalin(char s[])
{
	char *p=&s[0],*q=&s[strlen(s)-1];
	while(p<q)
		if(*p++!=*q--) return false;
	return true;
}

main()
{
	char s[5001],t[500];
	cin>>s;
	transform(&s[0],&s[strlen(s)],&s[0],::toupper);
	if(checkpalin(s))
	{
		int n=strlen(s)/2;
		for(int i=0;i<n;i++)
			t[i]=s[i];
		t[n]='\0';
		if(checkpalin(t)) cout<<"Double Palindrome";
		else cout<<"Palindrome";
	}
	else cout<<"No";
}
