#include<bits/stdc++.h>
using namespace std;

typedef struct {
	string name;
	int score;
	int difgoal;
	int goal;
}stats;

bool statscmp(stats a,stats b)
{
	return a.score>b.score||(a.score==b.score&&a.difgoal>b.difgoal)||(a.score==b.score&&a.difgoal==b.difgoal&&a.goal>b.goal);
}

main()
{
	string s[4];
	for(int i=0;i<4;i++)
		cin>>s[i];
	
	int t[4][4];
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			cin>>t[i][j];
	
	stats team[4];
	for(int i=0;i<4;i++)
	{
		team[i].name=s[i];
		team[i].score=0;
		team[i].difgoal=0;
		team[i].goal=0;
	}
	
	for(int i=1;i<4;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(t[i][j]>t[j][i]) team[i].score+=3;
			else if(t[i][j]<t[j][i]) team[j].score+=3;
			else
			{
				team[i].score++;
				team[j].score++;
			}
			
			team[i].difgoal+=t[i][j]-t[j][i];
			team[j].difgoal+=t[j][i]-t[i][j];
			
			team[i].goal+=t[i][j];
			team[j].goal+=t[j][i];
		}
	}

	sort(team,team+4,statscmp);
	
	for(int i=0;i<4;i++)
		cout<<team[i].name<<" "<<team[i].score<<endl;
		
}
