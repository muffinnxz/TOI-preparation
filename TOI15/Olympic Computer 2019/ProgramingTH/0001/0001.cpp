#include<iostream>
using namespace std;

main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int d=a+b+c;
	if(80<=d&&d<=100) cout<<"A";
	else if(75<=d&&d<=79) cout<<"B+";
	else if(70<=d&&d<=74) cout<<"B";
	else if(65<=d&&d<=69) cout<<"C+";
	else if(60<=d&&d<=64) cout<<"C";
	else if(55<=d&&d<=59) cout<<"D+";
	else if(50<=d&&d<=54) cout<<"D";
	else cout<<"F";
}
