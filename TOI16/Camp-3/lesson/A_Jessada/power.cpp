#include <iostream>
using namespace std;

int pow2(int m,int p,int n)
{
     int keep[64],sum;
     long long count[64];
     // 64 means 64bits.
     int i,j;
     // count[i] shows the power of m (the power becomes 2^i)
     // keep[j]  show (m^(count[i]) mod n)
     if (p==0) return 1;
     keep[0]=m;
     count[0]=1;
     count[1]=2;
     for (i=1;count[i]<=p;i++)
     {
         keep[i]=(keep[i-1]*keep[i-1])%n;
         count[i+1]=count[i]*2;
     }
     sum = keep[i-1];
     p=p-count[i-1];
     for (j=i-2;j>=0;j--)
       if (p>=count[j])
       {
          sum = sum*keep[j]%n;
          p   = p-count[j];
       }
     return sum%n;
}

int main()
{
    int i,n,m,p;
    cin >> n;
    for (i=0;i<n;i++)
    {
      cin >> m >> p;
      cout << pow2(m,p,1000); // m^p (mod 1000)
    }
    //scanf(" ");
    return 0;
}
