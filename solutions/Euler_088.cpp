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

bool destruct_search(vector <dotr> &t, int com, int com2)
{
    for(int i=0; i<t.size(); i++)
    {
        if(t[i].x == com && t[i].y == com2)
        {
            return true;
        }
    }
    return false;
}

vector <dotr> destruct(int add)
{
    vector <dotr> ans;
    for(int i=2; i<int(sqrt(add))+1; i++)
    {
        if(add%i == 0)
        {
            vector <dotr> tmp = destruct(i);
            for(int j=0; j<tmp.size(); j++)
            {
                if(!destruct_search(ans,tmp[j].x+add/i,tmp[j].y+1))
                {
                    ans.push_back({tmp[j].x+add/i,tmp[j].y+1});
                }
            }
            tmp = destruct(add/i);
            for(int j=0; j<tmp.size(); j++)
            {
                if(!destruct_search(ans,tmp[j].x+i,tmp[j].y+1))
                {
                    ans.push_back({tmp[j].x+i,tmp[j].y+1});
                }
            }
            if(!destruct_search(ans,add/i+i,2))
            {
                ans.push_back({add/i+i,2});
            }
        }
    }
    return ans;
}

void problem_88(int a)
{
    vector <bool> tackle(a+1,1);
    int counter = 1;
    set <int> tup;
    for(int i=4; i<a*2; i++)
    {
        cout<<"Number: "<<i<<endl;
        vector <dotr> y = destruct(i);

        for(int j=0; j<y.size(); j++)
        {
            int tmp = i-y[j].x+y[j].y;
            if(tmp < tackle.size())
                if(tackle[tmp])
                {
                    cout<<tmp<<" for i = "<<i<<endl;
                    tup.insert(i);
                    tackle[tmp] = 0;
                    counter++;
                }
        }
        if(counter==a)
        {
            break;
        }
    }
    cout<<"Number of splits: "<<counter<<endl;
    long long ans = 0;
    for(auto i = tup.begin(); i!=tup.end(); i++)
    {
        ans+= *i;
    }
    cout<<"Answer: "<<ans<<endl;
}

int main(){
    problem_88(12000);
    return 0;
}
