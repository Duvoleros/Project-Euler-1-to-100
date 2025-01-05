#include <cmath>
#include <iostream>

using namespace std;

int chain_make(int n)
{
    int a = sqrt(n);
    int b = sqrt(n);
    int mult = 1;
    cout<<a<<" ";
    bool flag = 0;
    int aa, bb, mm;
    for(int i=0; i<10000; i++)
    {

        int tmult = (n-b*b)/mult;
        int ta =0;
        while(sqrt(n)+b-(ta+1)*tmult >=0)
        {
            ta++;
        }
        int tb = tmult*(ta)-b;
        a = ta;
        b=tb;
        mult = tmult;
        if(flag)
        {
            if(aa==a && bb==b && mm ==mult)
            {
                cout<<endl;
                return i;
            }
        }
        else
        {
            aa= a;
            bb=b;
            mm = mult;
            flag = 1;
        }
        cout<<a;
    }
}

void problem_64(int n)
{
    long long sq = 1, ans = 0;
    for(long long i =1; i<=n; i++)
    {
        if(i==sq*sq)
        {
            sq++;
            continue;
        }
        if(chain_make(i)%2 ==1) ans++;
    }
    cout<<ans<<endl;
    return;
}

int main(){
    problem_64(1e4);
    return 0;
}