#include <iostream>
using namespace std;
#include <mem.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>
#define maxn 100000
char chkp[maxn],st[6];
int n,m,sum;

void think(int deep)
{
char chk[255],i,j,temp;
     memset(chk,0,sizeof(chk));
     if (deep==n) {if (chkp[atoi(st)]) sum++;}
     else
     {
        for (i=deep;i<n;i++)
        {
            if (chk[st[deep]]==0) think(deep+1);
            temp=st[deep];
            chk[temp]=1;
            for (j=deep;j<n-1;j++) st[j]=st[j+1];
            st[n-1]=temp;
        }
     }
}

void init_var()
{
     int i,j;
     memset(chkp, 1,sizeof(chkp));
     for (i=2;i<maxn;i++)
     if (chkp[i])
         for (j=2*i;j<maxn;j=j+i) chkp[j]=0;
}

int main()
{
    init_var();
    cin >> m >> n;
    int i;
    for (i=0;i<m;i++)
    {
        sum = 0;
        cin >> st;
        think(0);
        cout << sum << endl;
    }
    //getch();
    return 0;
}
