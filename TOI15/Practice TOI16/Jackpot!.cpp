#include<stdio.h>
int main()
{
	int n[3];
	int c[4]={0,0,0,0};
	int i;
	for(i=0;i<3;i++)
		scanf("%d",&n[i]);
	for(i=0;i<3;i++)
	{
		int temp=n[i]%4;
		int j=i;
		if(j==2) j++;
		if(temp==(4-j)%4) { printf("O "); c[0]++;}
		else if(temp==(5-j)%4) { printf("X "); c[1]++;}
		else if(temp==(6-j)%4) { printf("+ "); c[2]++;}
		else { printf("V "); c[3]++; }
	}
	if(c[0]==3||c[1]==3||c[2]==3||c[3]==3)
		printf("\nJACKPOT!");
	return 0;
}
