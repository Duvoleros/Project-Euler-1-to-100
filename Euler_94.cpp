#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

int gcd(long long a, long long b)
{
    while(b!=0)
    {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

void problem_94(int aa)
{
    long long summ = 0;
    for(long long int m = 2; m<sqrt(aa); m++)
    {
        for(long long int n = (m%2)+1; n<m; n+=2)
        {
            if(gcd(m,n)==1)
            {
                for(int k = 1; k<sqrt(aa); k++)
                {
                    long long a = (m*m-n*n)*k;
                    long long b = 2*m*n*k;
                    long long c = (m*m+n*n)*k;
                    if(2*c>aa)
                    {
                        break;
                    }
                    if(abs(b*2-c) == 1)
                    {
                        if((b+c)*2<=aa)
                        {
                            summ+=2*(c+b);
                            cout<<2*(c+b)<<" "<<c<<" "<<2*b<<endl;
                            cout<<"m: "<<m<<" n: "<<n<<" v "<<a<<" "<<b<<" "<<c<<endl;
                            cout<<summ<<endl;
                        }
                    }
                    if(abs(a*2-c)== 1)
                    {
                        if((a+c)*2<=aa)
                        {
                            summ+=2*(a+c);
                            cout<<2*(c+a)<<" "<<c<<" "<<2*a<<endl;
                            cout<<"m: "<<m<<" n: "<<n<<" v "<<a<<" "<<b<<" "<<c<<endl;
                            cout<<summ<<endl;
                        }
                    }
                }
            }

        }
    }
    return;
}

int main()
{
    problem_94(1e9);
    return 0;
}
