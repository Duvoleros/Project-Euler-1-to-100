
def sum_of_d(num):
    rez = 0
    while(num!=0):
        rez+=num%10
        num = num//10
    return rez
numbers = [2, 1]
for i in range(2, 100, 2):
    numbers.append(i)
    if(len(numbers)==100): break
    numbers.append(1)
    if(len(numbers)==100): break
    numbers.append(1)
    if(len(numbers)==100): break
numbers.reverse()
numbers
num, den = 1, numbers[0]
for i in range(1, len(numbers)):
    num, den = den, den*numbers[i]+num
    print(sum_of_d(num), sum_of_d(den))