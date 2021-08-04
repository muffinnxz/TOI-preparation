#include<iostream>
#include<queue>
#include<stack>
using namespace std;

int calculate(int n,int arr[])
{	
	int i;
	
	int ans=0;
	stack<int> tape;
	for(i=0;i<n;i++)
	{
		if(!tape.empty())
			while(arr[i]>=tape.top())
			{
				tape.pop();
				if(tape.empty()) break;
			}
	
		tape.push(arr[i]);

		ans+=tape.size();
	}
	return ans;
}
int main()
{
	int c;
	cin>>c;
	
	int i;
	int ans[c];
	for(i=0;i<c;i++)
	{
		int n;
		cin>>n;
		
		int inpu[n];
		
		for(int j=0;j<n;j++)
			cin>>inpu[j];
		
		ans[i]=calculate(n,inpu);
	}
	for(i=0;i<c;i++)
		cout<<ans[i]<<endl;
	
	return 0;
}
