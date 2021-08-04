#include<stdio.h>
#include<iostream>
#include<stack>
#include<string.h>

using namespace std;

void printStackSize(stack<char> tmp)
{
    int i=0;
    while(!tmp.empty())
    {
        i++;
        tmp.pop();
    }
    cout<<i;
}

int main()
{
    stack<char> optr;
    char txt[201],tmp;
    gets(txt);
    int miss_blan = 0 , n;
    n = strlen(txt);

    for(int i=0;i<n;i++)
    {
        optr.push(txt[i]);
        if(txt[i]==')')
        {
            if(!optr.empty())
            {
                optr.pop();
                if(optr.empty())
                {
                    optr.push(')');
                }
                else
                {
                    if(optr.top()=='(')
                    {
                        optr.pop();
                    }
                    else
                    {
                        optr.push(')');
                    }
                }
            }
        }
    }
    printStackSize(optr);
}
