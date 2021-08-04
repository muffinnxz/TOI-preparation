#include<bits/stdc++.h>
using namespace std;

bool isAllow(int a,int b,int nA,int nB,char c,char board[8][8])
{
	a+=nA;
	b+=nB;
	while(a>=0&&a<=8&&b>=0&&b<=8)
	{
		if(board[a][b]==c) return true;
		a+=nA;
		b+=nB;	
	}
	return false;
}

main()
{
	char board[8][8];
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			board[i][j]='.';
	board[3][3]='O'; board[3][4]='X';
	board[4][3]='X'; board[4][4]='O';
	
	int n;
	cin>>n;
	
	int x,y;
	char temp;
	for(int i=0;i<n;i++)
	{
		cin>>temp>>x;
		x--;
		y=(int)temp-'a';
		
		int c;
		
		if(i%2==0) c='X';
		else c='O';
		
		board[x][y]=c;
		
		for(int i=-1;i<=1;i++)
			for(int j=-1;j<=1;j++)
			{
				if(i==0&&j==0) continue;
				if(board[x+i][y+j]!='.'&&isAllow(x,y,i,j,c,board))
				{
					int a=x+i,b=y+j;
					while(board[a][b]!=c) 
					{
						board[a][b]=c;
						a+=i;
						b+=j;
					}
				}
			}
	}
	
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
			cout<<board[i][j];
		cout<<endl;
	}
}
