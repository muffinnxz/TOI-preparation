using namespace std;
#include<iostream>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

main()
{
	int n,i=0,j=0;
	
	scanf("%d",&n);
	
	int mat[n][n];
	char enter[2*n],sep[2];
	char *pch;
	
	scanf("%s",enter);
	
	pch=strtok(enter,":,");
	while(pch!=NULL)
	{
		sep[0]=*pch;
		sep[1]='\0';
		mat[i][j]=atoi(sep);
		j++;
		if(j>=n)
		{
			j=0;
			i++;
		}
		pch=strtok(NULL,":,");
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<mat[i][j]<<" ";
		cout<<endl;
	}			
}
