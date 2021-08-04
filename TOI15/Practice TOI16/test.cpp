#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  unsigned long long int n;
  cin>>n;
  int sum=0;
  for(unsigned long long int i=1;i<=n;i++)
  {
    cout<<i<<" ";
    sum+=i;
  }
  cout<<endl<<sum;
  return 0;
}
