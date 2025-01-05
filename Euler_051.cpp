#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <set>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int n_of(int n, int t)
{
    int ans = 0;
    while(n!=0)
    {
        if(n%10 == t)ans++;
        n/=10;
    }
    return ans;
}

void problem_51()
{
    fstream fin;
    fin.open("primes.txt");
    vector <int> primes;
    primes.reserve(660000);
    int tmp = 0;
    do
    {
        fin>>tmp;
        primes.push_back(tmp);
    }
    while(primes[primes.size()-1]<10000000);
    for(int i=0; i<primes.size(); i++)
    {
        if(primes[i]>100000 && n_of(primes[i],1)>2)
        {
            int value = n_of(primes[i],1);
            string str = to_string(primes[i]);
            for(int i1=0; i1<str.size(); i1++)
            {
                if(str[i1]=='1')
                {
                    for(int i2=i1+1; i2<str.size(); i2++)
                    {
                        if(str[i2]=='1')
                        {
                            for(int i3=i2+1; i3<str.size(); i3++)
                            {
                                if(str[i3]=='1')
                                {
                                    int co = 0;
                                    for(int k=0; k<10; k++)
                                    {
                                        str[i1] = '0'+k;
                                        str[i2] = '0'+k;
                                        str[i3] = '0'+k;
                                        if(binary_search(primes.begin(), primes.end(),stoi(str)))
                                        {
                                            co++;
                                        }
                                    }
                                    if(co>7)
                                    {
                                        int to_co = 0;
                                        for(int k=0; k<10; k++)
                                        {
                                            str[i1] = '0'+k;
                                            str[i2] = '0'+k;
                                            str[i3] = '0'+k;
                                            if(binary_search(primes.begin(), primes.end(),stoi(str)))
                                            {
                                                cout<<str<<endl;
                                                to_co++;
                                            }

                                        }
                                        cout<<"Size is "<<to_co<<endl;
                                    }
                                    str[i1] = '1';
                                    str[i2] = '1';
                                    str[i3] = '1';

                                }
                            }
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
    problem_51();
    return 0;
}
