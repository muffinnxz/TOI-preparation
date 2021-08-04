#include<iostream>
using namespace std;

#define n 10
#define m 10

int pic[n][m]={{0,0,0,0,1,0,0,0,0,0},
				 {0,0,0,1,0,0,0,0,0,0},
				 {0,0,1,0,0,0,0,0,0,0},
				 {0,1,0,0,0,0,0,0,0,0},
				 {1,0,0,0,0,0,0,0,0,0},
				 {0,0,0,0,0,0,0,0,0,0},
				 {0,0,0,0,0,0,0,0,0,0},
				 {0,0,0,0,0,0,0,0,0,0},
				 {0,0,0,0,0,0,0,0,0,0},
				 {0,0,0,0,0,0,0,0,0,0}};
				 
void ffilluntil(int pic[][m],int x,int y,int prevc,int newc)
{
	if(x<0||y<0||x>n||y>m) return;
	if(pic[x][y]!=prevc) return;
	
	pic[x][y]=newc;
	
	ffilluntil(pic,x+1,y,prevc,newc);
	ffilluntil(pic,x-1,y,prevc,newc);
	ffilluntil(pic,x,y+1,prevc,newc);
	ffilluntil(pic,x,y-1,prevc,newc);
}

void ffill(int pic[][m],int x,int y,int newc)
{
	int prevc=pic[x][y];
	ffilluntil(pic,x,y,prevc,newc);
}

void printpic(int pic[][m])
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<pic[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}
main()
{
	printpic(pic);
	ffill(pic,0,0,2);
	printpic(pic);
	ffill(pic,5,5,3);
	printpic(pic);
}
