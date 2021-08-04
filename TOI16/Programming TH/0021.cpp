#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;

main()
{
	char s[200];
	cin.getline(s,200);
	int n=strlen(s);
	for(int i=0;i<n;i++)
	{
		cout<<s[i];
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') i+=2;
	}
}
