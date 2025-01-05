#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <fstream>

using namespace std;

vector <vector <bool>> f(9, vector <bool> (9,0));
vector <vector <string>> val(9, vector <string> (9,"123456789"));
vector <int> tt;

void change_vals(int x, int y, char a)
{
    for(int i=0; i<val[x].size(); i++)
    {
        if(val[x][i].find(a)!=string::npos && f[x][i]==0)
        {
            val[x][i].erase(val[x][i].find(a)+val[x][i].begin());
            if(val[x][i].size()==1)
            {
                f[x][i] = 1;
                tt.push_back(x*9+i);
            }

        }
        if(val[i][y].find(a)!=string::npos && f[i][y]==0)
        {
            val[i][y].erase(val[i][y].find(a)+val[i][y].begin());
            if(val[i][y].size()==1)
            {
                f[i][y] = 1;
                tt.push_back(i*9+y);
            }

        }

    }
    for(int i=(x/3)*3; i<(x/3)*3+3; i++)
    {
        for(int j=(y/3)*3; j<(y/3)*3+3; j++)
        {
            if(val[i][j].find(a)!=string::npos && f[i][j]==0)
            {
                val[i][j].erase(val[i][j].find(a)+val[i][j].begin());
                if(val[i][j].size()==1)
                {
                    f[i][j] = 1;
                    tt.push_back(i*9+j);
                }

            }
        }
    }

}

void search_for()
{
    int cn = 0;
    for(int a=0; a<3; a++)
    {
        for(int b=0; b<3; b++)
        {
            vector<int> tmp(9,0);
            vector<int> tmp_pos(9,-1);
            for(int i=a*3; i<a*3+3; i++)
            {
                for(int j=b*3; j<b*3+3; j++)
                {
                    if(f[i][j]==0)
                    {
                        for(int k=0; k<val[i][j].size(); k++)
                        {
                            tmp[val[i][j][k]-'1'] +=1;
                            tmp_pos[val[i][j][k]-'1'] = i*9+j;
                        }
                    }
                }
            }
            for(int k = 0; k<9; k++)
            {
                if(tmp[k]==1)
                {
                    cn++;
                    tt.push_back(tmp_pos[k]);
                    f[tmp_pos[k]/9][tmp_pos[k]%9] = 1;
                    val[tmp_pos[k]/9][tmp_pos[k]%9] = '1'+k;
                }
            }
        }
    }
}

void compose96()
{
    while(tt.size()>0)
    {
        while(tt.size()>0)
        {
            change_vals(tt[0]/9,tt[0]%9,val[tt[0]/9][tt[0]%9][0]);
            tt.erase(tt.begin(),tt.begin()+1);
        }
        search_for();
    }
}

bool check_s()
{
    for(int k=0; k<81; k++)
    {
        if(val[k/9][k%9].size()>1)return 0;
    }
    int a =0, b =0;
    for(int k=0; k<81; k++)
    {
        a+=stoi(val[k/9][k%9]);
        b+=stoi(val[k%9][k/9]);
        if(k%9==8)
        {
            if(a!=45 || b!=45)return 0;
            a=0;
            b=0;
        }
    }
    for(int a=0; a<3; a++)
    {
        for(int b=0; b<3; b++)
        {
            int summ = 0;
            for(int i=a*3; i<a*3+3; i++)
            {
                for(int j=b*3; j<b*3+3; j++)
                {
                    summ+=stoi(val[i][j]);
                }
            }
            if(summ!=45) return 0;
        }
    }

    return 1;
}

bool nuclear9649()
{
    int temp = -1;
    for(int kk=0; kk<81; kk++)
    {
        if(val[kk/9][kk%9].size()>1)
        {
            temp = kk;
            break;
        }
    }
    if(temp==-1)
    {
        return check_s();
    }
    string str1 = val[temp/9][temp%9];
    vector <vector <bool>> tf = f;
    vector <vector <string>> tval = val;
    for(int i=0; i<str1.size(); i++)
    {
        val[temp/9][temp%9] = str1[i];
        f[temp/9][temp%9] = 1;
        tt.push_back(temp);
        compose96();
        if(nuclear9649()==1) return 1;
        val = tval;
        f = tf;
    }
    return 0;
}

void problem_96()
{
    int summ =0, counter = 0;
    fstream fin;
    fin.open("sudoku.txt");
    for(int c = 0; c<50; c++)
    {
        cout<<"    Problem "<<c+1<<endl;
        string str;
        getline(fin,str);
        for(int in =0; in<9; in++)
        {
            getline(fin,str);
            for(int i=0; i<9; i++)
            {
                if(str[i]!='0')
                {
                    val[in][i] = str[i];
                    f[in][i]=1;
                    tt.push_back(in*9+i);
                }
            }
        }
        compose96();
        if(!check_s())
        {
            int temp;
            for(int kk=80; kk>=0; kk--)
            {
                if(val[kk/9][kk%9].size()>1)
                {
                    temp = kk;
                    vector <vector <bool>> tf = f;
                    vector <vector <string>> tval = val;
                    string sh = val[temp/9][temp%9];
                    for(int k = 0; k<sh.size(); k++)
                    {
                        f = tf;
                        val = tval;
                        val[temp/9][temp%9] = sh[k];
                        tt.push_back(temp);
                        f[temp/9][temp%9] = 1;
                        compose96();
                        if(check_s()) break;
                    }
                    if(check_s()) break;
                    val = tval;
                    f = tf;
                }
            }

        }
        if(!check_s()) nuclear9649();
        if(check_s()) counter++;


        summ+=(val[0][0][0]-'0')*100+(val[0][1][0]-'0')*10+(val[0][2][0]-'0');
        for(int k=0; k<81; k++)
        {
            cout<<val[k/9][k%9]<<' ';
            if(k%9==8)
            {
                cout<<endl;
            }
            val[k/9][k%9]="123456789";
            f[k/9][k%9]=0;
        }
        cout<<endl;
    }
    cout<<summ<<" "<<counter<<endl;
    return;
}

int main(){
    problem_96();
    return 0;
}
