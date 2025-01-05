#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

struct dotr
{
    int x;
    int y;
};

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

bool comp2(dotr x, dotr y)
{
    if(x.y == y.y)
    {
        return x.x < y.x;
    }
    return x.y < y.y;
}

void problem_86(long long a)
{
    vector <dotr> Pt;
    set <string> ans;
    long long summ = 0;
    for(long long int m = 2; m<sqrt(20000000); m++)
    {
        for(long long int n = (m%2)+1; n<m; n+=2)
        {
            if(gcd(m,n)==1)
            {
                for(int k = 1; k<100000; k++)
                {
                    long long a = (m*m-n*n)*k;
                    long long b = 2*m*n*k;
                    long long c = (m*m+n*n)*k;
                    if(a>b)
                    {
                        c = a;
                        a = b;
                        b = c;
                    }
                    if(b<2000000)
                    {
                        Pt.push_back({a,b});
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
    sort(Pt.begin(),Pt.end(),comp2);
    cout<<Pt.size()<<endl;
    int result = 0;
    for(int i=0; i<1000000; i++)
    {
        if(ans.size()>=1000000)
        {
            cout<<"Answer: "<<i-1<<endl;
            break;
        }
        for(int j =0; j<Pt.size(); j++)
        {
            if(Pt[j].y>2*i) break;
            if(Pt[j].y == i)
            {
                result+=Pt[j].x/2;
                for(int k =0; k<Pt[j].x/2; k++)
                {
                    string kk = to_string(k)+" "+to_string((Pt[j].x-k))+" "+to_string(i);
                    ans.insert(kk);
                    result++;
                }
                continue;
            }
            if(Pt[j].x == i)
            {
                if(Pt[j].y<2*Pt[j].x)
                {
                    int t1 = Pt[j].y/2, t2 = Pt[j].y - t1;
                    while(t2<=Pt[j].x && t1>0)
                    {
                        string kk = to_string(t1)+" "+to_string(t2)+" "+to_string(i);
                        ans.insert(kk);
                        t2++;
                        t1--;
                        result++;
                    }
                }
                continue;
            }
        }
        cout<<i<<" "<<ans.size()<<endl;
    }
    cout<<ans.size();
    return;
}

int main(){
    problem_86(1e6);
    return 0;
}
