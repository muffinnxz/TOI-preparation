#include<stdio.h>
#include<iostream>
using namespace std;
void printFirstElementOfArray(int arr[])
{
    printf("Constant = %d\n",arr[0]);
}

void printAllElementOfArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("-%d\n", arr[i]);
    }
}

void printAllPossibleOrderedPairs(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d = %d\n", arr[i], arr[j]);
        }
     }
}
int fibonacci(int num)
{
    if (num <= 1) return num;
    return fibonacci(num - 2) + fibonacci(num - 1);
}

void printAllItemsTwice(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
	
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
}

int fac(int n)
{
	int i,ans=1;
	for(i=1;i<=n;i++)
	{
		ans*=i;
	}
	return ans;
}
main()
{
	int a[10]={0,1,2,3,4,5,6,7,8,9};
	int num=50;
	int i;
	printFirstElementOfArray(a);
	printAllElementOfArray(a,10);
	printAllPossibleOrderedPairs(a,10);
	/*for(i=1;i<=num;i++)
		cout<<fibonacci(i)<<"\n";*/
	printAllItemsTwice(a,10);
	cout<<fac(3);
}
