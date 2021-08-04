#include<iostream>
using namespace std;
main()
{
	int n,i,a;
	cin>>n;
	int max,min;
	for(i=0;i<n;i++)
	{
		cin>>a;
		if(i==0)
		{
			max=a;
			min=a;
		}
		if(max<=a) max=a;
		if(min>=a) min=a;
	}
	cout<<min<<endl<<max;
}
