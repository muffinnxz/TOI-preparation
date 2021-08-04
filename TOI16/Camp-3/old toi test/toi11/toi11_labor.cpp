#include <bits/stdc++.h>
using namespace std;

long long M,N;
long long l,r = INT_MAX,mid,cnt;
vector<int> a;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	cin>>M>>N;
	
    a.resize(M);
	for(int i=0;i<M;i++)
    {
        cin>>a[i];
        if(a[i]<r)
            r=a[i];
    }
    
    r=r*N;
    while(l<r)
    {
        mid=(l+r)/2;
        cnt = 0;
        for(int i=0;i<M;i++)
            cnt+=mid/a[i];
        if(cnt>=N) r=mid;
        else l=mid+1;
    }
    cout<<l;
}
