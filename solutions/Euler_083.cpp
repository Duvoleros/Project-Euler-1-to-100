#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct edge
{
    int to;
    int weigth;
};

void problem_83()
{
    int n, s, f;
    n = 80;
    s = 0;
    f = n*n-1;
    vector <vector<edge>> e(n*n);
    vector <int> qw(n*n, 214748361);
    vector <bool> check(n*n, 1);
    vector <int> touched;
    qw[s] = 0;
    touched.push_back(0);
    for(int i=0; i<n; i++)
    {
        string str;
        getline(cin,str);
        int tmp;
        for(int j=0; j<n-1; j++)
        {
            tmp = stoi(str.substr(0,str.find(',')));
            str.erase(0,str.find(',')+1);
            if(i!=0)
            {
                e[i*n+j].push_back({(i-1)*n+j,tmp});
            }
            if(i!=n-1)
            {
                e[i*n+j].push_back({(i+1)*n+j,tmp});
            }
            if(j!=0)
            {
                e[i*n+j].push_back({(i)*n+j-1,tmp});
            }
            e[i*n+j].push_back({(i)*n+j+1,tmp});
        }
        tmp = stoi(str);
        if(i!=0)
        {
            e[i*n+n-1].push_back({(i-1)*n+n-1,tmp});
        }
        if(i!=n-1)
        {
            e[i*n+n-1].push_back({(i+1)*n+n-1,tmp});
        }
        e[i*n+n-1].push_back({(i)*n+n-2,tmp});
    }

    for(int i=0; i<n*n; i++)
    {
        int an=214748361;
        int num=-1;
        for(int k=0; k<touched.size(); k++)
        {
            if(check[touched[k]]==1 && qw[touched[k]]<an)
            {
                an = qw[touched[k]];
                num = touched[k];
                swap(touched[0],touched[k]);
            }
        }
        touched.erase(touched.begin(),touched.begin()+1);
        if(num == -1)
        {
            cout<<"END";
            break;
        }
        else
        {
            check[num]=0;
            for(int j=0; j<e[num].size(); j++)
            {
                int to = e[num][j].to;
                if(qw[to]==214748361)
                {
                    touched.push_back(to);
                }
                qw[to] = min(qw[to], qw[num]+e[num][j].weigth);
            }
        }
    }
    if(qw[f]==214748361)
    {
        cout<<-1;
    }
    else
    {
        cout<<qw[f]+e[n*n-1][0].weigth<<endl;
    }
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<qw[i*80+j]<<" ";
        }
        cout<<endl;
    }
    return;
}

int main(){
    problem_83();
    return 0;
}