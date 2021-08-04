#include<iostream>
using namespace std;

main()
{
	int n;
	cin>>n;
	
	int location[n][2];
	int loc_check[n]={0};
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<2;j++)
			cin>>location[i][j];
			
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(location[i][0]>location[j][0]&&location[i][1]>location[j][1]) loc_check[j]=1;
	
	for(i=0;i<n;i++)
		if(loc_check[i]==0)
			cout<<location[i][0]<<" "<<location[i][1]<<endl;		
}
