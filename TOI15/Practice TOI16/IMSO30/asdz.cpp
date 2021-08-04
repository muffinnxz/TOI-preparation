#include<iostream>
#include<list>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
int m=0;
int calcu(int a[])
{
	int count=0;
	int i;
	for(i=0;i<98;i++)
	{
		count+=abs(a[i]-a[i+1]);
	}
	return count;
}

void findPermutations(int a[], int n) 
{ 
  
    sort(a, a + n); 
    do { 
    	int temp=calcu(a);
    	cout<<temp<<endl;
        if(temp>m) m=temp;
    } while (next_permutation(a, a + n)); 
} 

main()
{
	int a[99];
	for(int i=0;i<99;i++)
	{
		if(i==0) a[i]=1;
		else if(i%2==0) a[i]=i+1;
		else a[i]=99-i+1;	
	}
 	 for(int i=0;i<99;i++)
	{
		cout<<a[i]<<endl;	
	}
    cout<<calcu(a);
  	
    return 0;
}
