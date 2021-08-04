#include <iostream>
using namespace std;
#include <iomanip>
#include <conio.h>
#include <mem.h>
#define m 19
#define n 17
#define g 18
#define maxn 1000
int pace=maxn,trace[maxn][2],count=0,tr[maxn][2];
char chk[m+1][n+1];
void show()
{
     int i;
     if (pace==maxn) cout << "No solution!"; else
     {
       cout << pace-1 << endl;
       for (i=0;i<pace;i++)
           cout << setw(2) << i << setw(3) << trace[i][0] << setw(3) << trace[i][1] << endl;
     }
     //getch();
}
void think(int x,int y)
{
   if (count<pace-1 && chk[x][y]==0)
   //if (chk[x][y]==0)
   {
     tr[count][0]=x;
     tr[count][1]=y;
     count++;
     chk[x][y]=1;
     if (x==g || y==g)
     {
          pace = count;
          memcpy(trace,tr,sizeof(trace));
          //show();
     }
     else
     {
       think(m,y);
       think(x,n);
       think(0,y);
       think(x,0);
       if (x+y<=n) think(0,x+y); else think(x-(n-y),n);
       if (x+y<=m) think(x+y,0); else think(m,y-(m-x));
     }
     count--;
     chk[x][y]=0;
   }
}
int main()
{
    memset(tr,0,sizeof(tr));
    memset(chk,0,sizeof(chk));
    think(0,0);
    show();
    return 0;
}
