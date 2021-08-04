#include<iostream>

using namespace std;

int value[5] = {10,7,5,2,1};
int coin[100][3];

int change(int money)
{
    int i,temp,temp2,temp3;
    int number[5]={0,0,0,0,0};
    int min = 0;
    if((money>0)&&(coin[money][2]!=1))
    {
        min = 100;
        for(int i = 0 ; i<5 ; i++)
        {
            if(money>=value[i])
            {
                temp2 = (int) money/value[i];
                number[i] = temp2 + change(money%value[i]);
                if(number[i]<min)
                {
                    min = number[i];
                    temp = i;
                    temp3 = temp2;
                }
            }
        }

        coin[money][0] = value[temp];
        coin[money][1] = temp3;
        coin[money][2] = 1;
        return min;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int money;
    cin>>money;
    cout<<"At Least Total Coin : "<<change(money)<<endl;
}
