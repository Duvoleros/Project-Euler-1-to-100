#include <iostream>
#include <vector>

using namespace std;

int recurr61(vector<int> ans, vector <int> lin, vector <vector <int>> a)
{
    for(int j=0; j<5; j++)
    {
        if(lin[j]!=1)
        {
            for(int i=0; i<a[j].size(); i++)
            {
                if(a[j][i]%100 == ans[ans.size()-1]/100)
                {
                    ans.push_back(a[j][i]);
                    lin[j]=1;
                    if(ans.size()==6 && ans[ans.size()-1]/100 == ans[0]%100)
                    {
                        int summ =0;
                        for(int k =0; k<ans.size(); k++)
                        {
                            cout<<k+3<<" order, result is: "<<ans[k]<<endl;
                            summ+=ans[k];
                        }
                        cout<<"Sum of lines is: "<<summ<<endl;
                        break;
                    }
                    recurr61(ans,lin,a);
                    ans.pop_back();
                    lin[j]=0;
                }
            }
        }
    }
    return 0;
}

void problem_61()
{
    vector <vector <int>> a = {{},{},{},{},{},{}};
    for(int i=1; i<200; i++)
    {
        if((i*(i+1))/2 <10000 && (i*(i+1))/2>1000)
        {
            a[0].push_back((i*(i+1))/2);
        }
        if(i*i <10000 && i*i>1000)
        {
            a[1].push_back(i*i);
        }
        if((i*(3*i-1))/2 <10000 && (i*(3*i-1))/2>1000)
        {
            a[2].push_back((i*(3*i-1))/2);
        }
        if((i*(2*i-1)) <10000 && (i*(2*i-1))>1000)
        {
            a[3].push_back((i*(2*i-1)));
        }
        if((i*(5*i-3))/2 <10000 && (i*(5*i-3))/2>1000)
        {
            a[4].push_back((i*(5*i-3))/2);
        }
        if(i*(3*i-2) <10000 && i*(3*i-2)>1000)
        {
            a[5].push_back(i*(3*i-2));
        }
    }
    vector <int> ans;
    vector <int> lin = {0,0,0,0,0,1};
    for(int i=0; i<a[5].size(); i++)
    {
        ans.push_back(a[5][i]);
        recurr61(ans,lin,a);
        ans.clear();
    }

    for(int f=0; f<a.size(); f++)
    {
        for(int i=0; i<a[f].size(); i++)
        {
            cout<<a[f][i]<<" ";
        }
        cout<<endl;
        cout<<"Number of elements for "<<f+3<<" order is: "<<a[f].size()<<endl;
    }
    return;
}

int main(){
    problem_61();
    return 0;
}