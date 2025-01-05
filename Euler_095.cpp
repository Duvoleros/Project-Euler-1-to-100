#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long dividsS(int n)
{
    long long ans = 1;
    for(int i=2; i<sqrt(n); i++)
    {
        if(n%i==0)
        {
            ans+=n/i+i;
        }
    }
    if(int(sqrt(n))*int(sqrt(n))==n)
    {
        ans+=sqrt(n);
    }
    return ans;
}

void problem_95(int n)
{
    vector<int> a(n+2,0);
    for(int i=2; i<n+1; i++)
    {
        a[i] = dividsS(i);
        if(a[i]>=1000000)
        {
            a[i] = 0;
        }
    }
    vector <int> tt;
    for(int i=n; i>5; i--)
    {
        int temp = a[a[i]], counter = 1, u = -1;
        while(temp!=a[i] && temp!=0 &&temp!=u && !binary_search(tt.begin(), tt.end(), temp))
        {
            counter++;
            u = temp;
            temp = a[temp];
            if(counter>100)
            {
                break;
            }
        }
        if(counter>100 || temp!=0 && !binary_search(tt.begin(), tt.end(), temp))
        {
            tt.push_back(temp);
            sort(tt.begin(), tt.end());
        }
    }
    for(int i=0; i<tt.size(); i++)
    {
        int counter =1;
        int temp = tt[i];
        int minimum = temp;
        while(a[temp]!=tt[i])
        {
            counter++;
            temp = a[temp];
            minimum = min(temp, minimum);
            cout<<temp<<" ";
        }
        cout<<tt[i]<<endl;
        cout<< counter<<" "<<minimum<<endl;
    }
    return;
}

int main(){
    problem_95(1e6);
    return 0;
}
