#include<iostream>
#include<math.h>
using namespace std;

main()
{
	int n,k;
	cin>>n>>k;
	int i;
	float sum=0;
	float ttd=0;
	float v[n];
	for(i=0;i<n;i++)
	{
		cin>>v[i];
		sum+=v[i];
	}
	sum/=n;
	sum=roundf(sum);
	
	for(i=0;i<n;i++)
	{
		ttd+=abs(v[i]-sum);
	}
	cout<<ttd;
}
