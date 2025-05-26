factorial_list = [1]
for i in range(1,10):
    factorial_list.append(factorial_list[i-1]*i)
numbers = []
for i in range(3,1000000):
    temp = 0
    num = i
    while num!=0:
        temp+=factorial_list[num%10]
        num = num//10
    if(temp == i):
        numbers.append(i)
        print(i)

print(numbers)
    