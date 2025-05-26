#include <random>
#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>

using namespace std;

int chest(int n)
{
    int a = rand();
    if(a%16 == 15)
    {
        return 0;
    }
    if(a%16 == 9)
    {
        return 10;
    }
    return n;
}

int chance(int n)
{
    int a = rand(), b = n;
    switch(a%16)
    {
    case 0:
    {
        b = 0;
        break;
    }
    case 1:
    {
        b = 10;
        break;
    }
    case 2:
    {
        b = 11;
        break;
    }
    case 3:
    {
        b = 24;
        break;
    }
    case 4:
    {
        b = 39;
        break;
    }
    case 5:
    {
        b = 5;
        break;
    }
    case 6:
    {
        if((n%10)<5)
        {
            b = n-(n%10)+5;
        }
        else
        {
            b = n-(n%10)+15;
        }
        if(b>40)
        {
            b%=40;
        }
        break;
    }
    case 7:
    {
        if((n%10)<5)
        {
            b = n-(n%10)+5;
        }
        else
        {
            b = n-(n%10)+15;
        }
        if(b>40)
        {
            b%=40;
        }
        break;
    }
    case 8:
    {
        if(n<12 || n > 27)
        {
            b = 12;
        }
        else
        {
            n = 27;
        }
        break;
    }
    case 9:
    {
        b = (n-3)%40;
        break;
    }
    }
    return b;
}

void problem_84()
{
    vector <long long> atl(40,0);
    long long qw = 0;
    srand(time(NULL));
    int temp = 0;
    int d = 0;
    for(int i =0; i<100000000; i++)
    {
        int t1 = rand()%4 + 1;
        int t2 = rand()%4 + 1;
        temp = (temp+t1+t2) % 40;
        if(t1==t2) d++;
        if(temp == 22 || temp == 7 || temp == 36)
        {
            temp = chance(temp);
        }
        if(temp == 2 || temp == 17 || temp == 33)
        {
            temp = chest(temp);
        }
        if(temp == 30) temp = 10;
        if(d==3)
        {
            d=1;
            atl[10]++;
            continue;
        }
        atl[temp]++;
    }
    for(int i=0; i<40; i++)
    {
        cout<<i<<" "<<atl[i]<<" "<<(atl[i]*100.0)/100000000<<endl;
    }
    //monte-karlo method
    //possible problems with inner random generator
    return;
}

int main(){
    problem_84();
    return 0;
}
