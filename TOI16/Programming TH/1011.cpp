#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<vector<char> > board;
int allbomb = 0;

void swap(char *a,char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}

void drop(int x,int y,int N)
{
	for(int i=x;i<N-1;i++)
		if(board[i+1][y] == '-') swap(board[i][y],board[i+1][y]);
		else break;
}

void alldrop(int N,int M)
{
	for(int i=0;i<M;i++)
		for(int j=N-1;j>=0;j--)
			if(board[j][i] != '#' && board[j][i] != '-') drop(j,i,N);
}

bool candrop(int N,int M)
{
	for(int i=0;i<M;i++)
		for(int j=0;j<N-1;j++)
			if(board[j][i] != '#' && board[j][i] != '-' && board[j+1][i] == '-') return true;
	return false;
}

void bomb(int x,int y,int N,int M,char c)
{
	if(x<0||x>=N||y<0||y>=M) return;
	if(board[x][y] != c) return;
	
	board[x][y] = '-';
	allbomb ++;
	
	bomb(x+1,y,N,M,c);
	bomb(x-1,y,N,M,c);
	bomb(x,y+1,N,M,c);
	bomb(x,y-1,N,M,c);
}

void canbomb(int N,int M)
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(!isalpha(board[i][j])) continue;
			bool flag = false;
			if(i>0) if(board[i][j] == board[i-1][j]) flag = true;
			if(i<N-1) if(board[i][j] == board[i+1][j]) flag = true;
			if(j>0) if(board[i][j] == board[i][j-1]) flag = true;
			if(j<M-1) if(board[i][j] == board[i][j+1]) flag = true;
			if(flag) bomb(i,j,N,M,board[i][j]);
		}
	}
}
bool canmove(int x,int y,char d,int M)
{
	if(board[x][y] == '-' || board[x][y] == '#') return false;
	if(d == 'L' && y-1 < 0) return false;
	if(d == 'R' && y+1 >= M) return false;
	if(d == 'L' && board[x][y-1] == '-') return true;
	if(d == 'R' && board[x][y+1] == '-') return true;
	return false;  
}

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int N,M;
	cin>>N>>M;
	
	for(int i=0;i<N;i++)
		board.push_back(vector<char> (M));
		
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			cin>>board[i][j];
	
	int C;
	cin>>C;
	
	int x,y;
	char d;
	int score = 0;
	for(int i=0;i<C;i++)
	{
		cin>>x>>y>>d;
		if(canmove(x,y,d,M))
		{
			if(d == 'L') { swap(board[x][y],board[x][y-1]); y--;}
			else {swap(board[x][y],board[x][y+1]); y++;}
			do
			{
				alldrop(N,M);
				canbomb(N,M);
			}while(candrop(N,M));
		}
		else score -= 5;
	}
	cout<<score + allbomb * 5<<endl;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<M;j++)
			cout<<board[i][j]<<" ";
		cout<<endl;
	}
}
