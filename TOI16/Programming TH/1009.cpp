#include<bits/stdc++.h>
#include<string>
using namespace std;

long int lineToInt(string line[],int n)
{
	string num[10] = {" _ | ||_|","     |  |"," _  _||_ "," _  _| _|","   |_|  |"," _ |_  _|"," _ |_ |_|"," _   |  |"," _ |_||_|"," _ |_| _|"};
	int tmp = pow(10,n-1);
	bool c;
	long int sum = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<10;j++)
		{
			
			c = true;
			for(int x=0;x<3;x++)
			{
				for(int y=i*4;y<(i*4)+3;y++)
				{
					if(line[x][y] == 0 && isblank(num[j][x*3+(y-i*4)]) ) continue;
					if(line[x][y] != num[j][x*3+(y-i*4)]) c = false;
				}
			}
			if(c)
			{
				sum += j * tmp;
				tmp/=10;
				break;
			}
		}	
	}
	return sum;
}

void inBlankLine()
{
	string s;
	getline(cin,s);
}

main()
{
	int n,m;
	cin>>n>>m;
	
	inBlankLine();
	
	string line[3];
	long int A,B;
	
	for(int i=0;i<3;i++)
		getline(cin,line[i]);
	A = lineToInt(line,n);
	
	for(int i=0;i<3;i++)
		getline(cin,line[i]);
	B = lineToInt(line,m);
	
	cout<<A+B;
}
