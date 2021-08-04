#include<bits/stdc++.h>
#include<string>
using namespace std;

int strlen(string s)
{
	int i=0;
	while(s[i++]!='\0');
	return i-1;
}

int ctoi(char n)
{
	return (int)n-'0';
}

main()
{
	string s;
	cin>>s;
	
	int n=strlen(s);
	bool flag=false;
	int sum=0;
	do
	{
        if(flag)
        {
            s=to_string(sum);
            n=strlen(s);
            sum=0;
        }
		if(n%2==0)
		{
			for(int i=0;i<n-1;i+=2)
			{
				sum+=(ctoi(s[i])*10+ctoi(s[i+1]));
			}
			
		}
		else
		{
			sum+=ctoi(s[0]);
			for(int i=1;i<n-1;i+=2)
				sum+=(ctoi(s[i])*10+ctoi(s[i+1]));
		}
		flag=true;
	}while(sum>=100);
	cout<<sum%3<<" "<<sum%11;
}
