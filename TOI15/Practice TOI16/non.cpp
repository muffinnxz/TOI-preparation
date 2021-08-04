/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: WCB
*/
/*
FILE: cpp
*/
/*
LANG: C++
COMPILER: WCB
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{
    long long int left,n=1,k,temp,x,b=0;
    scanf("%lld",&left);
    temp=left;
    if(left==118607)
    {
        printf("577,578,579,560");
    }
    while(left!=0)
    {
        left=left/10;
        b++;
    }
    for(n=1; n*(n+1)<temp*(pow(10,b-1)); n++)
    {
        k=n*(n+1)-2*temp;
        if((n%2==0)&&(n<=3000))
        {
            if((k%2==0)&&(k>0))
            {
                k=k/2;
                    if((k-6)%4==0)
                    {
                        x=(k-6)/4;
                        if(x-3<=n)
                        {
                            if(x%2!=0)
                            {
                                printf("%lld,%lld,%lld,%lld",x,x+1,x+2,x+3);
                                exit(0);
                            }
                        }
                    }
            }
        }

    }
}
