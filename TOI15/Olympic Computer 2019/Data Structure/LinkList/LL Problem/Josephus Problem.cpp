#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
int josephus(int n, int k) 
{ 
  if (n == 1) 
    return 1; 
  else
    return (josephus(n - 1, k) + k-1) % n + 1; 
} 
main()
{
  int n,k;
  cin>>n;
  cin>>k;
  cout<<josephus(n,k);
}
