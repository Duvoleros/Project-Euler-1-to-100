#include <cmath>
#include <iostream>

using namespace std;

double chain_make2(int n)
{
    //copied from problem 64 with focus on logarithmic comparacences
    int a = sqrt(n);
    int b = sqrt(n);
    double answ = log(sqrt(n));
    int mult = 1;
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
                if(i%2==1)
                {
                    answ*=2;
                }
                return answ;
            }
        }
        else
        {
            aa= a;
            bb=b;
            mm = mult;
            flag = 1;
        }
        answ+=log(a);
    }
}


void problem_66(int n)
{
    long long sq = 1;
    double ans = 0;
    double tmp = -1;
    for(long long i =1; i<=n; i++)
    {
        if(i==sq*sq)
        {
            sq++;
            continue;
        }
        tmp = chain_make2(i);
        if(tmp>ans)
        {
            ans = tmp;
            cout<<endl;
            cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<i<<endl;
            cout<<endl;
        }
        //Pell's equation
        //cout<<"Pell: "<<(long long) (sqrt(temp*temp*i+1)) <<endl;
    }
    cout<<ans<<endl;
    return;
}

int main(){
    problem_66(1e3);
    return 0;
}
