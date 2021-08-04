#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,a,b,k;
    scanf("%d",&n);
    
    int sum[n];
    sum[0] = 0;
	
    scanf("%d",&a);
    
    for(int i=1; i<n; i++)
    {
        scanf("%d",&b);
        if(b>a) sum[i] = b-a+sum[i-1];
        else sum[i] = sum[i-1];
        a = b;
    }
    
    int q;
    scanf("%d",&q);
    for(int i=0; i<q; i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",sum[b-1]-sum[a-1]);
    }
}
