#include<iostream>
using namespace std;

int gcd(int a, int b) 
{ 
    if(a < b) 
        return gcd(b, a); 
    else if(a%b == 0) 
        return b; 
    else return gcd(b, a%b);   
} 
main()
{
	int c=0;
	int i,j;
	int n=1,m=100000;
	for(i=n;i<=m;i++)
	{
		for(j=i+1;j<=m;j++)
		{
			if(gcd(i,j)==1)
			{
				cout<<i<<" "<<j<<endl;
				c++;
			}	
		}
	}
	cout<<c;
}
