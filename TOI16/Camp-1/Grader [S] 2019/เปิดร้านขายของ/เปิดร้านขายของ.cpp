#include <iostream>
#include <math.h>
using namespace std;

int main() 
{
  int n;
  cin>>n;
  
  int q[n][4];
  for(int i=0;i<n;i++)
    for(int j=0;j<4;j++)
      cin>>q[i][j];

  for(int i=0;i<n;i++)
  {
  	int temp=0;
    int a=q[i][0],b=q[i][1],p=q[i][2],r=q[i][3];
    int flag=0;
    for(int j=a;j<=b;j++)
    {
      for(int k=p;k<=sqrt(j);k++)
      {
        if(k>r) break;
        if(j%k!=0) continue;
        else if(j/k<=r&&j/k>=p) 
		{
			temp++;
			if(k==j/k) flag++;
		}
      }
    }
	if(temp!=1) temp=temp*2-flag;
    cout<<temp<<endl;
  }
  return 0;
}
