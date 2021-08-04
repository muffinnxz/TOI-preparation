#include<bits/stdc++.h>
using namespace std;

int kadaneAlgorithm(int arr[],int n)
{
	int max = INT_MIN, temp = 0;
	int start = 0,end = 0,s = 0;
	for(int i=0;i<n;i++)
	{
		temp += arr[i];
		
		if(max < temp) 
		{
			max = temp;	
			start = s;
			end = i;
		}
		
		if(temp < 0)
		{
			temp = 0;
			s = i + 1;
		}	
	}
	
	if(max > 0)
	{
		for(int i=start;i<=end;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
	
	return max;
}

main()
{
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++) 
		cin>>arr[i];
		
	int max_sum = kadaneAlgorithm(arr,n);
	if(max_sum > 0) cout<<max_sum;
	else cout<<"Empty sequence";
}
