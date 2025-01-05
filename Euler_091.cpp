#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    while(b!=0)
    {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

void problem_91(int n)
{
    long long answ = 0;
    answ+=n*n*3;
    cout<<answ<<" ";
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int x = i/gcd(j,i), y = j/gcd(j,i);
            int x1 = i, y1 = j;
            int count_ = 0;
            while(x1-y>=0 && y1+x<=n)
            {
                count_+=1;
                x1-=y;
                y1+=x;
            }
            x1 = i, y1 = j;
            while(x1+y<=n && y1-x>=0)
            {
                count_+=1;
                x1+=y;
                y1-=x;
            }
            answ+=count_;
        }
        cout<<i<<" "<<answ<<endl;
    }
    cout<<answ;
    return;
}

int main(){
    problem_91(50);
    return 0;
}