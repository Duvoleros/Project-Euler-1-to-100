def sum_of_divisors(number):
    index = 2
    rezult = 1
    square = number**0.5
    while(index<=square):
        if(number%index==0):
            rezult+=index
            rezult+=number//index
        index+=1
    if((int(square))**2==number):
        rezult-=int(square)
    return rezult

list_ = [0,1]
for i in range(2,10001):
    list_.append(sum_of_divisors(i))
sum = 0
for i in range(2,10001):
    if(list_[i]<10000):
        if(i == list_[list_[i]] and list_[i]!=i):
            sum+=i
            print(i)
print(sum)