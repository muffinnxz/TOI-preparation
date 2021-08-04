#include<iostream>
using namespace std;

int pic[10][10]={{0,0,0,0,1,0,0,0,0,0},
				 {0,0,0,1,0,0,0,0,0,0},
				 {0,0,1,0,0,0,0,0,0,0},
				 {0,1,0,0,0,0,0,0,0,0},
				 {1,0,0,0,0,0,0,0,0,0},
				 {0,0,0,0,0,0,0,0,0,0},
				 {0,0,0,0,0,0,0,0,0,0},
				 {0,0,0,0,0,0,0,0,0,0},
				 {0,0,0,0,0,0,0,0,0,0},
				 {0,0,0,0,0,0,0,0,0,0}};

void ppic()
{
	int i,j;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
			cout<<pic[i][j];
		cout<<endl;
	}
	cout<<endl;
}

void ffilluntil(int pic[][10],int x,int y,int prevc,int newc)
{
	if (x < 0 || x >= 10 || y < 0 || y >= 10) 
        return; 
    if (pic[x][y] != prevc) 
        return; 
  
 
    pic[x][y] = newc; 
  
    ffilluntil(pic, x+1, y, prevc, newc); 
    ffilluntil(pic, x-1, y, prevc, newc); 
    ffilluntil(pic, x, y+1, prevc, newc); 
    ffilluntil(pic, x, y-1, prevc, newc); 
}

void floodFill(int pic[][10], int x, int y, int newc) 
{ 
    int prevc = pic[x][y]; 
    ffilluntil(pic,x,y,prevc,newc); 
} 
  
int main()
{
	ppic();
	floodFill(pic,0,0,2);
	ppic();
}
