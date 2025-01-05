def transform(number):
    sum =0
    while number!=0:
        sum+=(number%10)**2
        number = number//10
    return sum


num89 = []


def binary_search(number):
    first = 0
    last = len(num89)-1
    while(last-first>1):
        middle = (first+last)//2
        if(num89[middle]<number):
            first = middle
        else:
            last = middle
    return num89[last]


numbers = 0  
Flag = True
for i in range(2,600):#we put to array all numbers below 600 as after 1 transform any number with 7 digits is less than 600
    list_ = [i]
    Flag = True
    while(Flag):
        num = transform(list_[-1])
        for j in range(0,len(list_)):
            if(num == list_[j]):
                if(num != 1):
                    numbers+=1
                    print(i,89)
                else:
                    print(i,num)
                    num89.append(i)
                Flag = False
                break
        list_.append(num)
num89.sort()
for i in range(600,10000001):
    value = transform(i)
    if(not binary_search(value)==value):
        numbers+=1
print(numbers)