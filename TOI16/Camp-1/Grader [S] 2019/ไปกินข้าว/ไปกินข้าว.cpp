#include<iostream>
#include<list>
#include<vector>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int findp()
{
	int n;
	cin>>n;
	
	int i,j;
	list<int> man_in;
	int temp;
	for(i=0;i<3;i++)
	{
		cin>>temp;
		temp--;
		man_in.push_back(temp);
	}
	
	int t[2][n],s[2][n];
	for(i=0;i<n;i++)
		cin>>t[0][i]>>s[0][i]>>t[1][i]>>s[1][i];
		
	man_in.sort();
	man_in.unique();
	
	vector<int> man;
	while(!man_in.empty())
	{
		man.push_back(man_in.front());
		man_in.pop_front();
	}
	
	int ans_min=-1;
	if(man.size()==1&&man[0]==0) return 0;
	do {
		
		/*cout<<"-> ";
		for(i=0;i<man.size();i++)
			cout<<man[i]<<" ";
		cout<<endl;*/
		
		int min;
		for(i=0;i<pow(2,man.size());i++)
		{
			list<int> sample;
			int num=i;
			for(j=0;j<man.size();j++)
			{
				sample.push_front(num%2);
				num/=2;
			}
			int sum=0;
			vector<int> now(2,0);
			vector<int> time(2,0);
			for(j=0;j<man.size();j++)
			{
				int x=sample.front();
				sample.pop_front();
				//cout<<x<<" : "<<now[x]<<" -> "<<man[j]<<" = "<<( abs(t[x][man[j]]-t[x][now[x]])+s[x][man[j]] )<<endl;
				time[x]+=( abs(t[x][man[j]]-t[x][now[x]])+s[x][man[j]] );
				now[x]=man[j];
			}
			
			if(now[0]!=0) time[0]+=( abs(t[0][0]-t[0][now[0]])+s[0][0] );
			if(now[1]!=0) time[1]+=( abs(t[1][0]-t[1][now[1]])+s[1][0] );
			
			if(time[0]>time[1]) sum=time[0];
			else sum=time[1];
			
			//cout<<"ANS : "<<sum<<endl;
			
			if(i==0) min=sum;
			else if(sum<min) min=sum;
		}
		
     	if(ans_min==-1) ans_min=min;
     	else if(min<ans_min) ans_min=min;
     	
    } while (next_permutation(man.begin(),man.end()));
	return ans_min;
}

int main()
{
	int t;
	cin>>t;
	int ans[t];
	for(int i=0;i<t;i++)
		ans[i]=findp();
	for(int i=0;i<t;i++)
		cout<<ans[i]<<endl;
	return 0;
}

