#include<iostream>
using namespace std;
int fact_r(int n)
{
	if(n==1) return 1;
	else return n*fact_r(n-1);
}
main()
{
	int a[5]={1,2,3,4,5};
	int b[5]={4,5,6,7,8};
	int i,j;
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			if(a[i]==b[j])printf("%d\n",a[i]);
}
