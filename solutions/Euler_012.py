def num_of_divisors(number):
    index = 1
    rezult = 0
    square = number**0.5
    while(index<=square):
        if(number%index==0):
            print(number/index, index)
            rezult+=2
        index+=1
    if((int(square))**2==number):
        rezult-=1
    return rezult

index = 1
triangle = 1
while(num_of_divisors(triangle)<501):
    index+=1
    triangle+=index
print(triangle)