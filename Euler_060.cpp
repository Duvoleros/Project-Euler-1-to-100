#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

long long int concat(long long int a, long long int b)
{
    return stoi(to_string(a)+to_string(b));
}

void problem_60()
{
    vector <int> n = {3, 7, 109, 673};
    fstream fin;
    fin.open("primes.txt");
    vector <long long> primes;
    primes.reserve(10000);
    int temp = 0;
    do
    {
        primes.push_back(temp);
    }
    while(fin>>temp);
    for(int i=1; primes[i]<10000; i++)
    {
        for(int j=i+1; primes[j]<10000; j++)
        {
            if(binary_search(primes.begin(), primes.end(), concat(primes[j], primes[i]))&&binary_search(primes.begin(), primes.end(), concat( primes[i], primes[j])))
                for(int k=j+1; primes[k]<10000; k++)
                {
                    bool f =1;
                    f = f &&  binary_search(primes.begin(), primes.end(), concat(primes[j], primes[k]));
                    f = f &&  binary_search(primes.begin(), primes.end(), concat(primes[k], primes[j]));
                    f = f &&  binary_search(primes.begin(), primes.end(), concat(primes[k], primes[i]));
                    f = f &&  binary_search(primes.begin(), primes.end(), concat(primes[i], primes[k]));
                    if(f)
                    {
                        //cout<<primes[k]<<" "<<primes[i]<<" "<<primes[j]<<endl;
                        for(int l=k+1; primes[l]<10000; l++)
                        {
                            bool f2 =1;
                            f2 = f2 &&  binary_search(primes.begin(), primes.end(), concat(primes[j], primes[l]));
                            f2 = f2 &&  binary_search(primes.begin(), primes.end(), concat(primes[l], primes[j]));
                            f2 = f2 &&  binary_search(primes.begin(), primes.end(), concat(primes[l], primes[i]));
                            f2 = f2 &&  binary_search(primes.begin(), primes.end(), concat(primes[i], primes[l]));
                            f2 = f2 &&  binary_search(primes.begin(), primes.end(), concat(primes[l], primes[k]));
                            f2 = f2 &&  binary_search(primes.begin(), primes.end(), concat(primes[k], primes[l]));
                            if(f2)
                            {
                                //cout<<primes[l]<<" "<<primes[k]<<" "<<primes[j]<<" "<<primes[i]<<endl;
                                for(int m=l+1; primes[m]<40000; m++)
                                {
                                    int flag = 1;
                                    flag = flag +(binary_search(primes.begin(), primes.end(), concat(primes[i], primes[m])));
                                    flag = flag +(binary_search(primes.begin(), primes.end(), concat(primes[m], primes[i])));
                                    flag = flag +(binary_search(primes.begin(), primes.end(), concat(primes[j], primes[m])));
                                    flag = flag +(binary_search(primes.begin(), primes.end(), concat(primes[m], primes[j])));
                                    flag = flag +(binary_search(primes.begin(), primes.end(), concat(primes[m], primes[k])));
                                    flag = flag +(binary_search(primes.begin(), primes.end(), concat(primes[k], primes[m])));
                                    flag = flag +(binary_search(primes.begin(), primes.end(), concat(primes[l], primes[m])));
                                    flag = flag +(binary_search(primes.begin(), primes.end(), concat(primes[m], primes[l])));
                                    if(flag>8)
                                    {
                                        cout<<primes[m]<<" "<<primes[l]<<" "<<primes[k]<<" "<<primes[j]<<" "<<primes[i]<<endl;
                                        cout<<primes[m]+primes[l]+primes[k]+primes[j]+primes[i]<<endl;
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

int main(){
    problem_60();
    return 0;
}