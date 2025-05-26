import math

numbers = input().split(" ")
rez = [1,1]
for i, number in enumerate(numbers):
    numbers[i] = [int(number.split(",")[0]),int(number.split(",")[1])]

for i, num in enumerate(numbers):
    if(math.log(rez[0], num[0])*rez[1]/num[1]<=1):
        rez = num
        print(i+1,rez)