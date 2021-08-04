#include<stdio.h>
using namespace std;
#include<stdlib.h>
#include<iostream>

main()
{
	int n,m;
	float c[10];
	cin>>n>>m;
	float map[n][m];
	float valley,ocean,plain;
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			cin>>map[i][j];
			if(map[i][j]==0) ocean++;
			else if(map[i][j]==1) plain++;
			else valley++;
		}
	float op,pp,vp,all;
	all=n*m;
	op=ocean/all*100;
	pp=plain/all*100;
	vp=valley/all*100;
	if(op>pp&&op>vp)
		cout<<"OCEAN"<<endl;
	else if(pp>op&&pp>vp)
		cout<<"PLAIN"<<endl;
	else if(vp>pp&&vp>op)
		cout<<"Valley"<<endl;
		
	cout<<"OCEAN percent = "<<op<<endl;
	cout<<"Plain percent = "<<pp<<endl;
	cout<<"Valley percent = "<<vp<<endl;
}
