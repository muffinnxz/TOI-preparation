#include<bits/stdc++.h>
using namespace std;

double arr[1001];

double fo(int n)
{
	if(arr[n] != -1 ) return arr[n];
	
	arr[n] = fmod(fo(n-1) + fo(n-3) + fo(n-4),2557);
	
	return arr[n];
} 

main()
{
	arr[1] = 1;
	arr[2] = 0;
	arr[3] = 2;
	arr[4] = 4;
	arr[5] = 6;
	arr[6] = 9;
	arr[7] = 15;
	arr[8] = 25;
	
	for(int i=9;i<=1000;i++)
		arr[i] = -1;
		
	for(int i=1;i<=1000;i++)
		printf("%d -> %.0lf\n",i,fo(i));
}
