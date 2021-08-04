#include<bits/stdc++.h>
#include<vector>
using namespace std;

main()
{
	char tc,Va,Vb;
	int tn;
	int data[26]={0};
	vector<int> ans;
	while(true)
	{
		scanf("%c",&tc);
		if(tc=='!')
		{
			break;
		}
		else if(tc=='#')
		{
			scanf("%*c%c",&tc);
			ans.push_back(data[int(tc)-65]);
		}
		else if(tc=='=')
		{
			scanf("%*c%c%d",&tc,&tn);
			data[int(tc)-65]=tn;
		}
		else if(tc=='+') 
		{
			scanf("%*c%c%*c%c",&Va,&Vb);
			data[int(Va)-65]+=data[int(Vb)-65];
		}
		else if(tc=='-')
		{
			scanf("%*c%c%*c%c",&Va,&Vb);
			data[int(Va)-65]-=data[int(Vb)-65];
		}
		else if(tc=='*')
		{
			scanf("%*c%c%*c%c",&Va,&Vb);
			data[int(Va)-65]*=data[int(Vb)-65];
		}
		else if(tc=='/')
		{
			scanf("%*c%c%*c%c",&Va,&Vb);
			data[int(Va)-65]/=data[int(Vb)-65];
		}
	}
	
	int sizeans=ans.size();
	for(int i=0;i<sizeans;i++)
		printf("%d\n",ans[i]);
	cout<<"!";
}
