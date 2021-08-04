#include<iostream>
#include<math.h>
#include<list>
using namespace std;
bool check_palin(int num)
{
	int n, digit, rev = 0;
    n = num;
    do
    {
        digit = num % 10;
        rev = (rev * 10) + digit;
        num = num / 10;
    }while (num != 0);
    if (n == rev)
        return true;
    else
        return false;
}
bool check_palin_2(int n)
{
	list<int> z;
	while(n!=0)
	{
		z.push_front(n%2);
		n/=2;
	}
	while(!z.empty())
	{
		if(z.front()!=z.back()) return false;
		if(z.size()==1) z.pop_front();
		else
		{
			z.pop_front();
			z.pop_back();	
		}
	}
	return true;
}
main()
{
	int i;
	int count=0;
	for(i=1;i<=100000;i++)
	{
		if(check_palin(i)&&check_palin_2(i))
			count++;
	}
	cout<<count;
}
