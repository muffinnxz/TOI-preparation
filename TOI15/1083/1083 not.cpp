#include<bits/stdc++.h>
using namespace std;
main()
{
    int n,num,k;
    //cin>>n;
    scanf("%d",&n);
    vector<int>stock,sum;
    sum.push_back(0);
    //cin>>num;
    scanf("%d",&num);
    stock.push_back(num);
    for(int i=1; i<n; i++)
    {
        //cin>>num;
        scanf("%d",&num);
        stock.push_back(num);
        if(stock[1]>stock[0])
        {
            sum.push_back(stock[1]-stock[0]+sum[i-1]);
        }
        else
            sum.push_back(sum[i-1]);
        stock.erase(stock.begin());
    }
    int q;
    //cin>>q;
    scanf("%d",&q);
    for(int i=0; i<q; i++)
    {
        int a,b;
        //cin>>a>>b;
        scanf("%d%d",&a,&b);
        //cout<<sum[b-1]-sum[a-1]<<endl;
        printf("%d\n",sum[b-1]-sum[a-1]);
    }
}
