#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

bool check_93(double a)
{
    if((int(a)-a)<0.0000001 || (int(a)+1-a)<0.0000001 && a>0) return 1;
    else return 0;
}

void problem_93()
{
    int finale = 0;
    string s;
    for(int i=0; i<7; i++)
    {
        for(int j=i+1; j<8; j++)
        {
            for(int k=j+1; k<9; k++)
            {
                for(int l=k+1; l<10; l++)
                {
                    string str = to_string(i)+to_string(j)+to_string(k)+to_string(l);
                    vector <int> rez;
                    int t1, t2, t3, t4;
                    double tmp;
                    for(int ii=0; ii<4; ii++)
                    {
                        t1 = (str[ii])-'0';
                        str.erase(ii,1);
                        tmp = t1;
                        for(int jj=0; jj<3; jj++)
                        {
                            t2 = str[jj]-'0';
                            str.erase(jj,1);
                            tmp+=t2;
                            for(int kk=0; kk<2; kk++)
                            {
                                t3 = (str[kk])-'0';
                                t4 = (str[(1+kk)%2])-'0';
                                if(check_93(tmp+t3+t4)) rez.push_back(round(tmp+t3+t4));
                                if(check_93(tmp+t3-t4)) rez.push_back(round(tmp+t3-t4));
                                if(check_93((tmp+t3)*t4)) rez.push_back(round((tmp+t3)*t4));
                                if(check_93((tmp+t3)/t4)) rez.push_back(round((tmp+t3)/t4));

                                if(check_93(tmp-t3+t4)) rez.push_back(round(tmp-t3+t4));
                                if(check_93(tmp-t3-t4)) rez.push_back(round(tmp-t3-t4));
                                if(check_93((tmp-t3)*t4)) rez.push_back(round((tmp-t3)*t4));
                                if(check_93((tmp-t3)/t4)) rez.push_back(round((tmp-t3)/t4));

                                if(check_93(tmp*t3+t4)) rez.push_back(round(tmp*t3+t4));
                                if(check_93(tmp*t3-t4)) rez.push_back(round(tmp*t3-t4));
                                if(check_93((tmp*t3)*t4)) rez.push_back(round((tmp*t3)*t4));
                                if(check_93((tmp*t3)/t4)) rez.push_back(round((tmp*t3)/t4));

                                if(check_93(tmp/t3+t4)) rez.push_back(round(tmp/t3+t4));
                                if(check_93(tmp/t3-t4)) rez.push_back(round(tmp/t3-t4));
                                if(check_93((tmp/t3)*t4)) rez.push_back(round((tmp/t3)*t4));
                                if(check_93((tmp/t3)/t4)) rez.push_back(round((tmp/t3)/t4));
                            }
                            tmp-=t2;
                            tmp-=t2;
                            for(int kk=0; kk<2; kk++)
                            {
                                t3 = (str[kk])-'0';
                                t4 = (str[(1+kk)%2])-'0';
                                if(check_93(tmp+t3+t4)) rez.push_back(round(tmp+t3+t4));
                                if(check_93(tmp+t3-t4)) rez.push_back(round(tmp+t3-t4));
                                if(check_93((tmp+t3)*t4)) rez.push_back(round((tmp+t3)*t4));
                                if(check_93((tmp+t3)/t4)) rez.push_back(round((tmp+t3)/t4));

                                if(check_93(tmp-t3+t4)) rez.push_back(round(tmp-t3+t4));
                                if(check_93(tmp-t3-t4)) rez.push_back(round(tmp-t3-t4));
                                if(check_93((tmp-t3)*t4)) rez.push_back(round((tmp-t3)*t4));
                                if(check_93((tmp-t3)/t4)) rez.push_back(round((tmp-t3)/t4));

                                if(check_93(tmp*t3+t4)) rez.push_back(round(tmp*t3+t4));
                                if(check_93(tmp*t3-t4)) rez.push_back(round(tmp*t3-t4));
                                if(check_93((tmp*t3)*t4)) rez.push_back(round((tmp*t3)*t4));
                                if(check_93((tmp*t3)/t4)) rez.push_back(round((tmp*t3)/t4));

                                if(check_93(tmp/t3+t4)) rez.push_back(round(tmp/t3+t4));
                                if(check_93(tmp/t3-t4)) rez.push_back(round(tmp/t3-t4));
                                if(check_93((tmp/t3)*t4)) rez.push_back(round((tmp/t3)*t4));
                                if(check_93((tmp/t3)/t4)) rez.push_back(round((tmp/t3)/t4));
                            }
                            tmp+=t2;
                            tmp*=t2;
                            for(int kk=0; kk<2; kk++)
                            {
                                t3 = (str[kk])-'0';
                                t4 = (str[(1+kk)%2])-'0';
                                if(check_93(tmp+t3+t4)) rez.push_back(round(tmp+t3+t4));
                                if(check_93(tmp+t3-t4)) rez.push_back(round(tmp+t3-t4));
                                if(check_93((tmp+t3)*t4)) rez.push_back(round((tmp+t3)*t4));
                                if(check_93((tmp+t3)/t4)) rez.push_back(round((tmp+t3)/t4));

                                if(check_93(tmp-t3+t4)) rez.push_back(round(tmp-t3+t4));
                                if(check_93(tmp-t3-t4)) rez.push_back(round(tmp-t3-t4));
                                if(check_93((tmp-t3)*t4)) rez.push_back(round((tmp-t3)*t4));
                                if(check_93((tmp-t3)/t4)) rez.push_back(round((tmp-t3)/t4));

                                if(check_93(tmp*t3+t4)) rez.push_back(round(tmp*t3+t4));
                                if(check_93(tmp*t3-t4)) rez.push_back(round(tmp*t3-t4));
                                if(check_93((tmp*t3)*t4)) rez.push_back(round((tmp*t3)*t4));
                                if(check_93((tmp*t3)/t4)) rez.push_back(round((tmp*t3)/t4));

                                if(check_93(tmp/t3+t4)) rez.push_back(round(tmp/t3+t4));
                                if(check_93(tmp/t3-t4)) rez.push_back(round(tmp/t3-t4));
                                if(check_93((tmp/t3)*t4)) rez.push_back(round((tmp/t3)*t4));
                                if(check_93((tmp/t3)/t4)) rez.push_back(round((tmp/t3)/t4));
                            }
                            tmp/=t2;
                            tmp/=t2;
                            for(int kk=0; kk<2; kk++)
                            {
                                t3 = (str[kk])-'0';
                                t4 = (str[(1+kk)%2])-'0';
                                if(check_93(tmp+t3+t4)) rez.push_back(round(tmp+t3+t4));
                                if(check_93(tmp+t3-t4)) rez.push_back(round(tmp+t3-t4));
                                if(check_93((tmp+t3)*t4)) rez.push_back(round((tmp+t3)*t4));
                                if(check_93((tmp+t3)/t4)) rez.push_back(round((tmp+t3)/t4));

                                if(check_93(tmp-t3+t4)) rez.push_back(round(tmp-t3+t4));
                                if(check_93(tmp-t3-t4)) rez.push_back(round(tmp-t3-t4));
                                if(check_93((tmp-t3)*t4)) rez.push_back(round((tmp-t3)*t4));
                                if(check_93((tmp-t3)/t4)) rez.push_back(round((tmp-t3)/t4));

                                if(check_93(tmp*t3+t4)) rez.push_back(round(tmp*t3+t4));
                                if(check_93(tmp*t3-t4)) rez.push_back(round(tmp*t3-t4));
                                if(check_93((tmp*t3)*t4)) rez.push_back(round((tmp*t3)*t4));
                                if(check_93((tmp*t3)/t4)) rez.push_back(round((tmp*t3)/t4));

                                if(check_93(tmp/t3+t4)) rez.push_back(round(tmp/t3+t4));
                                if(check_93(tmp/t3-t4)) rez.push_back(round(tmp/t3-t4));
                                if(check_93((tmp/t3)*t4)) rez.push_back(round((tmp/t3)*t4));
                                if(check_93((tmp/t3)/t4)) rez.push_back(round((tmp/t3)/t4));
                            }
                            tmp*=t2;
                            str.insert(jj,to_string(t2));
                        }
                        str.insert(ii,to_string(t1));
                    }
                    sort(rez.begin(),rez.end());
                    int temporary = 0;
                    for(int ii=rez.size()-2; ii>=0; ii--)
                    {
                        if(rez[ii+1]==rez[ii] || rez[ii]<0)
                        {
                            rez.erase(rez.begin()+ii,rez.begin()+ii+1);
                        }
                    }
                    for(int ii=rez.size()-1; ii>=0; ii--)
                    {
                        if(rez[ii]==ii+1)
                        {
                            temporary = rez[ii];
                            break;
                        }
                    }
                    if(temporary>finale)
                    {
                        finale = temporary;
                        cout<<str<<" "<<finale<<endl;
                    }
                }
            }
        }
    }
    return;
}

int main(){
    problem_93();
    return 0;
}
