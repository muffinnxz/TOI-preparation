#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<list>
#include<stack>
#include<queue>
#include<string.h>
using namespace std;

main()
{
	char c[1000],temp[2],op;
	char *pch;
	gets(c);
	stack<char> operater,mark;
	stack<int> number;
	int i;
	for(pch=&c[0];*pch!='\0';pch++)
	{
		if(*pch=='('||*pch==')') mark.push(*pch);
		else if(*pch=='+'||*pch=='-'||*pch=='*'||*pch=='/') operater.push(*pch);
		else
		{
			temp[0]=*pch;
			temp[1]='\0';
			number.push(atoi(temp));	
		}
		if(mark.top()==')')
		{
			mark.pop();
			mark.pop();
			op=operater.top();
			operater.pop();
			int b=number.top();
			number.pop();
			int a=number.top();
			number.pop();
			if(op=='+') number.push(a+b);
			else if(op=='-') number.push(a-b);
			else if(op=='*') number.push(a*b);
			else number.push(a/b);
		}
	}
	cout<<number.top();
}
