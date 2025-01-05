#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int transform_(int number){
    int sum = 0;
    while (number!=0){
        sum+=(number%10)*(number%10);
        number = number/10;
    }
    return sum;
}

int main(){
    std::vector <int> num89(0);
    for(int i = 1;i<600;i++){
        int temp = i;
        cout<<i<<endl;
        while(temp!=1 && temp!=89){
            temp = transform_(temp);
            cout<<temp<<" ";
        }
        if(temp == 89){
            num89.push_back(i);
        }
    }
    int rezult = num89.size();
    sort(num89.begin(),num89.end());
    for(int i=600;i<10000001;i++){
        rezult+=binary_search(num89.begin(), num89.end(), transform_(i));
    }
    cout<<rezult<<endl;
    return 0;
}
