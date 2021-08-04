#include<stdio.h>
#include<time.h>
int fibo(int a)
{
	if(a<3) return 1;
	else return fibo(a-1)+fibo(a-2);
}

void forfibo()
{
	int i;
	int a=0,b=1,c=1;
	for(i=0;i<10;i++)
	{
		printf("%d ",c);
		c=a+b;
		a=b;
		b=c;
	}
}
main()
{
	clock_t t;
    t = clock();
	int n;
	forfibo();
	
	float diff = ((float)(clock() - t)) / CLOCKS_PER_SEC ;
    printf ("\n\n diff=%f \n\n", diff);
}
