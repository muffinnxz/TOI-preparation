//01 DAIFUGO PROGRAM
#include<iostream>

using namespace std;

int CardToInt(char v);
int SuitToInt(char s);
char IntToCard(int vi);
char IntToSuit(int si);

int main()
{
    int card[13][4] = {0},n;
    cin>>n;
    char value,suit;

    for(int i=0;i<n;i++)
    {
        cin>>value>>suit;
        if(card[CardToInt(value)][SuitToInt(suit)]==0)
        {
            card[CardToInt(value)][SuitToInt(suit)]++;
        }
    }

    for(int i=0;i<13;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(card[i][j]!=0)
            {
                cout<<IntToCard(i)<<" "<<IntToSuit(j)<<endl;
            }
        }
    }
}

int CardToInt(char v)
{
    switch(v)
    {
        case '3' : return 0; break;
        case '4' : return 1; break;
        case '5' : return 2; break;
        case '6' : return 3; break;
        case '7' : return 4; break;
        case '8' : return 5; break;
        case '9' : return 6; break;
        case 'T' : return 7; break;
        case 'J' : return 8; break;
        case 'Q' : return 9; break;
        case 'K' : return 10; break;
        case 'A' : return 11; break;
        case '2' : return 12; break;
        default : break;
    }
}

int SuitToInt(char s)
{
    switch(s)
    {
        case 'C' : return 0; break;
        case 'D' : return 1; break;
        case 'H' : return 2; break;
        case 'S' : return 3; break;
        default : break;
    }
}

char IntToCard(int vi)
{
    switch(vi)
    {
        case 0 : return '3'; break;
        case 1 : return '4'; break;
        case 2 : return '5'; break;
        case 3 : return '6'; break;
        case 4 : return '7'; break;
        case 5 : return '8'; break;
        case 6 : return '9'; break;
        case 7 : return 'T'; break;
        case 8 : return 'J'; break;
        case 9 : return 'Q'; break;
        case 10 : return 'K'; break;
        case 11 : return 'A'; break;
        case 12 : return '2'; break;
        default : break;
    }
}

char IntToSuit(int si)
{
    switch(si)
    {
        case 0 : return 'C'; break;
        case 1 : return 'D'; break;
        case 2 : return 'H'; break;
        case 3 : return 'S'; break;
        default : break;
    }
}
