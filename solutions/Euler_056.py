def sum_of_digits(l):
    sum = 0
    while(l>0):
        sum+=l%10
        l=l//10
    return sum

rez = 1
for i in range(2,100):
    if(i%10 !=0):
        number = i
        for j in range(2,101):
            number*=i
            rez = max(rez, sum_of_digits(number))
    print(i, rez)