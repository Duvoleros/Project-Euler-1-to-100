#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct deck
{
    int arr[5][15];
    int M_flush = 0;
    int flush = 0;
    int flushQ = 0;
    int M_flushQ = 0;
    int M = 0;
    int t2 = 0;
    int t1 = 0;
    int t3 = 0;
    int t4 = 0;
};

deck write_deck(deck a1, string str)
{

    for(int i=0; i<5; i++)
    {
        int tmp = 0;
        switch(str[0])
        {
        case 'J':
            tmp = 110;
            break;
        case 'T':
            tmp = 100;
            break;
        case 'Q':
            tmp = 120;
            break;
        case 'K':
            tmp = 130;
            break;
        case 'A':
            tmp = 140;
            break;
        default:
            tmp = (str[0]-'0')*10;
            break;
        }
        switch(str[1])
        {
        case 'H':
            tmp += 1;
            break;
        case 'S':
            tmp += 2;
            break;
        case 'C':
            tmp += 3;
            break;
        case 'D':
            break;
        }
        a1.arr[tmp%10][tmp/10-2]++;
        a1.arr[4][tmp/10-2]++;
        a1.arr[tmp%10][13]++;
        a1.M = max(a1.M, tmp/10-2);
        a1.arr[4][13] = max(a1.arr[4][13],a1.arr[4][tmp/10-2]);
        str.erase(0,2);
    }
    for(int i=0; i<5; i++)
    {
        int tmp = 0;
        for(int j=0; j<13; j++)
        {
            if(a1.arr[i][j]!=0)
            {
                tmp++;
            }
            else
            {
                if(tmp>a1.flush && i!=4)
                {
                    a1.flush = tmp;
                    a1.M_flush = j;
                }
                if(tmp>a1.flushQ && i==4)
                {
                    a1.flushQ = tmp;
                    a1.M_flushQ = j;
                }
                a1.arr[i][14] = max(a1.arr[i][14], tmp);
                tmp = 0;
            }
        }
        if(tmp>a1.flush && i!=4)
        {
            a1.flush = tmp;
            a1.M_flush = 13;
        }
        if(tmp>a1.flushQ && i==4)
        {
            a1.flushQ = tmp;
            a1.M_flushQ = 13;
        }
        a1.arr[i][14] = max(a1.arr[i][14], tmp);
        tmp = 0;
    }
    for(int j=12; j>=0; j--)
    {
        switch(a1.arr[4][j])
        {
        case 2:
            if(a1.t1!=0)
            {
                a1.t2 = a1.t1;
            }
            else
            {
                a1.t1 = j+1;
            }
            break;
        case 3:
            a1.t3 = j+1;
            break;
        case 4:
            a1.t4 = j+1;
            break;
        }
    }
    return a1;
}

bool compare_decks(deck a1, deck a2)
{
    if(a1.flush==5 && a2.flush<a1.flush)
    {
        return 1;
    }
    if(a2.flush==5 && a2.flush>a1.flush)
    {
        return 0;
    }
    if(a1.t4>a2.t4)
    {
        return 1;
    }
    if(a2.t4>a1.t4)
    {
        return 0;
    }
    if(a1.t3>0&&a1.t1>0&&a2.t1==0)
    {
        return 1;
    }
    if(a2.t3>0&&a2.t1>0&&a1.t1==0)
    {
        return 0;
    }
    if(a1.t3>0&&a1.t1>0&&a2.t3>0&&a2.t1>0)
    {
        if(a1.t3>a2.t3)
            return 1;
        if(a2.t3>a1.t3)
            return 0;
        if(a1.t1>a2.t1)
            return 1;
        if(a2.t1>a1.t1)
            return 0;
    }
    int tmp1 = max(max(a1.arr[0][13],a1.arr[1][13]),max(a1.arr[2][13],a1.arr[3][13]));
    int tmp2 = max(max(a2.arr[0][13],a2.arr[1][13]),max(a2.arr[2][13],a2.arr[3][13]));
    if(tmp1 == 5 || tmp2 == 5)
    {
        if(tmp1>tmp2)
        {
            return 1;
        }
        if(tmp1<tmp2)
        {
            return 0;
        }
        return (a1.M>a2.M);
    }
    if(a1.flushQ==5 && a2.flushQ<a1.flushQ)
    {
        return 1;
    }
    if(a2.flushQ==5 && a2.flushQ>a1.flushQ)
    {
        return 0;
    }
    if(a1.t3>a2.t3)
    {
        return 1;
    }
    if(a1.t3<a2.t3)
    {
        return 0;
    }
    if(a1.t2>a2.t2)
    {
        return 1;
    }
    if(a1.t2<a2.t2)
    {
        return 0;
    }
    if(a1.t1>a2.t1)
    {
        return 1;
    }
    if(a1.t1<a2.t1)
    {
        return 0;
    }
    return (a1.M>a2.M);
}

void problem_54()
{
    int ans = 0;
    deck a1;
    for(int ii=0; ii<1000; ii++)
    {
        deck a1;
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<15; j++)
            {
                a1.arr[i][j] = 0;
            }
        }
        deck a2;
        for(int i=0; i<5; i++)
        {
            for(int j=0; j<15; j++)
            {
                a2.arr[i][j] = 0;
            }
        }
        string str;
        getline(cin,str);
        for(int i=0; i<str.length(); i++)
            if(str[i] == ' ') str.erase(i,1);
        a1 = write_deck(a1,str.substr(0,10));
        str.erase(0,10);
        a2 = write_deck(a2,str);
        ans+=compare_decks(a1,a2);
    }
    cout<<ans;
    return;
}

int main(){
    problem_54();
    return 0;
}
