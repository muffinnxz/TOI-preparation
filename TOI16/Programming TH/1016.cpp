#include<bits/stdc++.h>
#include<string>
using namespace std;

int ctoi(char n)
{
	return n - '0';
}

main()
{
	double x = 0, y = 0;
	char cmd[10];
	
	while(true)
	{
		cin>>cmd;
		double d = 0;
		char n[3];
		
		if(cmd[0] == '*') break;
		
		char *p = &cmd[0];
		while(isdigit(*p)) p++;
		int di = p - &cmd[0];
		for(int i=0;i<di;i++)
			d += ctoi(cmd[i]) * pow(10,di - i -1);
		di = 0;
		while(*p != '\0') n[di++] = *p++;
		n[di] = '\0';
		
		double s = d / sqrt(2);
		
		if(!strcmp(n,"N")) y += d;
		else if(!strcmp(n,"S")) y -= d; 
		else if(!strcmp(n,"E")) x += d;
		else if(!strcmp(n,"W")) x -= d;
		else if(!strcmp(n,"NW"))
		{
			x -= s;
			y += s;
		}
		else if(!strcmp(n,"NE"))
		{
			x += s;
			y += s;
		}
		else if(!strcmp(n,"SE"))
		{
			x += s;
			y -= s;
	 	}
		else 
		{
			x -= s;
			y -= s;
		}
	}
	printf("%.3f %.3f\n%.3f",x,y,sqrt(x*x+y*y));
}
