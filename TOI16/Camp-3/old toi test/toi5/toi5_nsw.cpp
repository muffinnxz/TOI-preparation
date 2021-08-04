#include<bits/stdc++.h>
#include<string>
using namespace std;

int change(int a,int b)
{
	int temp = ((a + b) % 9);
	if(temp == 0 ) temp = 9;
	return temp - 1;
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	char sc[4],code[300];
	cin>>sc>>code;
	
	int s[3],t[3];
	for(int i=0;i<3;i++)
		s[i] = (int)(sc[i] - '0');
	for(int i=0;i<3;i++)
		t[i] = s[i];
	int len = strlen(code);
	int temp;
	int output[len];
	
	for(int i=0;i<len;i++)
	{
		temp = (int)(code[i] - '0') - 1;
		temp = change(temp,s[0]);
		temp = change(temp,s[1]);
		temp = change(temp,s[2]) + 1;
		s[0] = change(s[0],t[0]) + 1;
		s[1]--; if(s[1] == 0) s[1] = 9;
		s[2] = change(s[2],t[2]) + 1;
		output[i] = temp;
	}
	
	for(int i=0;i<len;i++)
		cout<<output[i];
}
