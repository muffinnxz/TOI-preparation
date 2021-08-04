#include<iostream>
using namespace std;

bool nugget_set[102]={false};

int recur_nug(int n,int a,int b,int c)
{
	if(n>101) return 0;
	nugget_set[n]=true;
	recur_nug(n+a,a,b,c);
	recur_nug(n+b,a,b,c);
	recur_nug(n+c,a,b,c);
}

main()
{
	recur_nug(0,6,9,20);
	int n;
	cin>>n;
	int i;
	bool check=false;
	for(i=6;i<=n;i++)
		if(nugget_set[i]) 
		{
			cout<<i<<endl;
			check=true;
		} 
	if(!check) cout<<"no";
}
