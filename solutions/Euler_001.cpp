//initial python code was lost in time, that is 2024 version
#include <iostream>

void problem_1()
{
    long long limit = 1000-1;
    long long ans15 = limit/15;// 1 7 13 19 S(u) = (a1+an/2)*n
    long long ans3 = limit/3;
    long long ans5 = limit/5;
    long long answer = 3*(1+ans3)*ans3/2+5*(1+ans5)*ans5/2-15*(1+ans15)*ans15/2;
    std::cout<<"Answer: "<<answer<<std::endl;
    return;
}

int main()
{
    problem_1();
    return 0;
}
