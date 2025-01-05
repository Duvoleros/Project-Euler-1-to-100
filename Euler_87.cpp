#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <fstream>

using namespace std;

void problem_87(long long n)
{
    fstream fin;
    fin.open("primes20k.txt");
    vector <int> primes;
    primes.reserve(200);
    set <int> nums;
    int tmp = 0;
    do
    {
        fin>>tmp;
        primes.push_back(tmp);
    }
    while(primes[primes.size()-1]<sqrt(n));
    for(int i=0; i<primes.size(); i++)
    {
        tmp = primes[i]*primes[i];
        for(int j=0; j<primes.size(); j++)
        {
            tmp +=primes[j]*primes[j]*primes[j];
            if(tmp>=n)
            {
                break;
            }
            for(int k=0; k<primes.size(); k++)
            {
                int tes = primes[k]*primes[k]*primes[k]*primes[k];
                if(tes+tmp>n)
                {
                    break;
                }
                nums.insert(tes+tmp);
            }
            tmp -=primes[j]*primes[j]*primes[j];
        }
    }
    cout<<nums.size();
    return;
}

int main()
{
    problem_87(5e6);
    return 0;
}
