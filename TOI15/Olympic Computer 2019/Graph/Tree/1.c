#include <stdio.h>
#include <stdlib.h>
int N;
void f(int x)
{
    int i,v;
    for(i=0;i<N;i++)
    {
        v=(x&(1<<i))!=0;
        if(v==1)
            printf("x");
        else
            printf("o");
    };
    printf("\n");
}
int main()
{
    int i;
    scanf("%d",&N);
    int n=pow(2,N);
    for(i=0;i<=n;i++)
        f(i);
    return 0;
}
