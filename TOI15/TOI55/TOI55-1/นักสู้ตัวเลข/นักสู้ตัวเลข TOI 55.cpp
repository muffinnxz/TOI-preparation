#include<iostream>
using namespace std;
main()
{
	int p;
	cin>>p;
	int pp=2*p;
	int n,i,hp1=p,hp2=p;
	int combo1=0,combo2=0;
	for(i=0;i<pp;i++)
	{
		cin>>n;
		
		if(n%2==0)
		{
			combo1=0;
			combo2++;
			if(combo2<3)
				hp1--;
			else hp1-=3;
		}
		else
		{
			combo1++;
			combo2=0;
			if(combo1<3)
				hp2--;
			else hp2-=3;
		}
		
		if(hp1<=0)
		{
			cout<<"0"<<endl;
			cout<<n;
			break;
		}
		if(hp2<=0)
		{
			cout<<"1"<<endl;
			cout<<n;
			break;
		}
	}
}
