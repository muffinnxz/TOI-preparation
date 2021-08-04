#include<bits/stdc++.h>
using namespace std;

int N, M, X, L[11], A[11], S[10000001], T[1000001], Q[N];

main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> X;
	
	for(int i=0;i<N;i++)
		cin >> N[i];
	for(int i=0;i<N;i++)
		cin >> A[i];
	for(int i=0;i<M;i++)
		cin >> S[i];
	for(int i=0;i<X;i++)
		cin >> T[i];
	for(int i=0;i<T;i++)
		for(int j=0;j<N;j++)
			cin >> Q[i][j];
	
	
}
