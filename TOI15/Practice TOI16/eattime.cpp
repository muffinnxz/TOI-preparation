#include<iostream>
#include<list>
#include<math.h>
using namespace std;

int calcu()
{
	int n;
	cin>>n;
	
	int i;
	list<int> man;
	for(i=0;i<3;i++)
	{
		int temp;
		cin>>temp;
		temp--;
		man.push_back(temp);
	}
	
	//man.sort();
	
	int t[2][n],s[2][n];
	for(i=0;i<n;i++)
		cin>>t[0][i]>>s[0][i]>>t[1][i]>>s[1][i];
	
	int nowf[2];
	int timef[2];
	int timefex[2];
	for(i=0;i<2;i++)
	{
		nowf[i]=0;
		timef[i]=0;
		timefex[i]=0;
	}
	while(!man.empty())
	{
		int temp=man.front();
		man.pop_front();
		
		if(nowf[0]==temp||nowf[1]==temp) continue;
	
		int a=abs(t[0][temp]-t[0][nowf[0]])+s[0][temp];
		int b=abs(t[1][temp]-t[1][nowf[1]])+s[1][temp];
		
		if(timef[0]==timef[1])
		{
			if(a<b)
			{
				timef[0]+=a;
				nowf[0]=temp;
				timefex[0]+=b;
			}
			else if(a>b)
			{
				timef[1]+=b;
				nowf[1]=temp;
				timefex[1]+=a;
			}
			else if(abs(t[0][0]-t[0][nowf[0]])+s[0][0]<abs(t[1][0]-t[1][nowf[1]])+s[1][0])
			{
				timef[0]+=a;
				nowf[0]=temp;
				timefex[0]+=b;
			}
			else
			{
				timef[1]+=b;
				nowf[1]=temp;
				timefex[1]+=a;
			}
		}
		else if(timef[0]<timef[1])
		{
			timef[0]+=a;
			nowf[0]=temp;
			timefex[0]+=b;
		}
		else
		{
			timef[1]+=b;
			nowf[1]=temp;
			timefex[1]+=a;
		}
		
	}
	
	if(nowf[0]!=0) 
	{
		timef[0]+=abs(t[0][0]-t[0][nowf[0]])+s[0][0];
		timefex[0]+=abs(t[1][0]-t[1][nowf[0]])+s[1][0];
	}
	
	if(nowf[1]!=0) 
	{
		timef[1]+=abs(t[1][0]-t[1][nowf[1]])+s[1][0];
		timefex[1]+=abs(t[0][0]-t[0][nowf[1]])+s[0][0];
	}
	
	cout<<"ANS : "<<timef[0]<<" "<<timef[1]<<endl;
	cout<<"EX ANS : "<<timefex[0]<<" "<<timefex[1]<<endl;
	
	int btimea,btimeb;
	if(timef[0]>timef[1]) btimea=timef[0];
	else btimea=timef[1];
	
	if(timefex[0]>timefex[1]) btimeb=timefex[0];
	else btimeb=timefex[1];
	
	if(btimea>btimeb) return btimeb;
	else return btimea;
}
int main()
{
	int c;
	cin>>c;
	
	int ans[c];
	for(int i=0;i<c;i++)
		ans[i]=calcu();
	for(int i=0;i<c;i++)
		cout<<ans[i]<<endl;
	return 0;
}

