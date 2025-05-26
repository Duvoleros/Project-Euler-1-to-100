import math

d = 10**6

prime_numbers = []
f = open("primes.txt", "r")
for i in f.readlines():
    if(int(i)<d):
        prime_numbers.append(int(i))

def get_factors(num):
    factors = []
    index = 0 
    #print("Source number is ",num)
    while(num>1):#and index<len(prime_numbers)):
        if(num%prime_numbers[index] == 0):
            #print("The begining ",index,prime_numbers[index],num)
            factors.append(prime_numbers[index])
            while(num%prime_numbers[index] == 0):
                num //= prime_numbers[index]
            #print("The end      ",index,prime_numbers[index],num)
        index+=1
    return factors

def totient(num):
    factors = get_factors(num)
    rez = num
    for factor in factors:
        rez *= factor - 1
        rez = rez // factor
    return rez

rez = 1
prime_index = 2
for i in range(3, d+1):
    if(prime_index!=len(prime_numbers)):
        if(i == prime_numbers[prime_index]):
            rez+=i-1
            prime_index+=1
            continue
    rez+=totient(i)
    if(i%1000 == 0):
        print(i, rez)
print((rez))
