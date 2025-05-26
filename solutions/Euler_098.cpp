#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <fstream>

using namespace std;

struct dotr
{
    int x;
    int y;
};

string transform_98(string str)
{
    string ans = "aaaaaaaaaaaaaaaaaaaaaaaaaa";
    for(int i=0; i<str.size(); i++)
    {
        ans[str[i]-'A'] = ans[str[i]-'A'] + 1;
    }
    return ans;
}

bool check_mask_98(string str, int n)
{
    string str2 = to_string(n);
    if(str2.size()!=str.size()) return 0;
    if(n%10==0) return 0;
    for(int i=0; i<str.size(); i++)
    {
        for(int j=0; j<str.size(); j++)
        {
            if(str[i]==str[j] && str2[i]!=str2[j]) return 0;
            if(str[i]!=str[j] && str2[i]==str2[j]) return 0;
        }
    }
    return 1;
}

int permutation98(string str1, string str2, int n)
{
    string str3 = to_string(n);
    string ans = "";
    for(int i=0; i<str2.size(); i++)
    {
        int temp = 0;
        while(str1[temp]!=str2[i])
        {
            temp++;
        }
        ans = ans+str3[temp];
    }
    return stoi(ans);
}

void problem_98()
{

    string str;
    fstream fin;
    fin.open("euler_98_words.txt");
    vector <string> s;
    vector <string> s_e;
    vector <dotr> pairs;
    vector <int> squares = {1};
    while(fin>>str)
    {
        int i_begin, i_end;
        cout<<endl;
        cout<<str<<endl;
        while(str!="")
        {
            i_begin = 0;
            i_end = 0;
            while(str[i_begin]==',' || str[i_begin]=='"')
            {
                i_begin++;
                i_end++;
            }
            while(str[i_end]!=',' && str[i_end]!='"')
            {
                i_end++;
                if(i_end == str.size()) break;
            }
            string tmp = str.substr(i_begin,i_end-i_begin);
            str.erase(0,i_end);
            if(tmp.size()>1)
                s.push_back(tmp);
        }
    }
    int max_size = 0;
    for(int i=0; i<s.size(); i++)
    {
        s_e.push_back(transform_98(s[i]));
        cout<<i<<" "<<s_e[i]<<" "<<s[i]<<endl;
    }
    for(int i=0; i<s.size()-1; i++)
        for(int j=i+1; j<s.size(); j++)
        {
            if(s_e[i]==s_e[j])
            {
                cout<<s[i]<<" | "<<s[j]<<endl;
                pairs.push_back({i,j});
                if(s[i].size()>max_size)
                {
                    max_size = s[i].size();
                }
            }
        }
    int tmp = 2;
    while(squares[squares.size()-1]<pow(10,max_size))
    {
        squares.push_back(tmp*tmp);
        tmp++;
    }
    cout<<squares.size()<<endl;
    int answer = 0;
    for(int i=0; i<pairs.size(); i++)
    {
        for(int j=0; j<squares.size(); j++)
        {
            if(check_mask_98(s[pairs[i].x],squares[j]))
            {
                int tt = permutation98(s[pairs[i].x],s[pairs[i].y],squares[j]);
                if(binary_search(squares.begin(), squares.end(), tt) && to_string(tt).size()==to_string(squares[j]).size())
                {
                    cout<<s[pairs[i].x]<<" | "<<s[pairs[i].y]<<" |||| "<<squares[j]<<" "<<tt<<endl;
                    answer = max(answer, squares[j]);
                    answer = max(tt, answer);
                }
            }
        }
    }
    cout<<"Answer: "<<answer<<endl;
    return;
}

int main(){
    problem_98();
    return 0;
}
