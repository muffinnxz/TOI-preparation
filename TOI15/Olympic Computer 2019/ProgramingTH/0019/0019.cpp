#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int N;
int S[10],B[10];
int allstate(int x)
{
    int i,v,s=1,b=0;
    for(i=0;i<N;i++)
    {
        v=(x&(1<<i))!=0;
        if(v==1)
        {
        	s*=S[i];
			b+=B[i];	
		}   
    }
    return abs(s-b);
}
main()
{
    int j,i,min=10000000;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
    	scanf("%d %d",&S[i],&B[i]);
	}
    int n=pow(2,N)-1;
    for(i=1;i<=n;i++)
    {
    	if(min>=allstate(i))
			min=allstate(i);
	}
	printf("%d",min);
}
