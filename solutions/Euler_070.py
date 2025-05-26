import math

file = open("primes200k.txt", "r")
rez = 1
primes_list = []
for i in file.readlines():
    if(int(i)<10**7):
        primes_list.append(int(i))

def check_nums(num1, num2):
    num1_list = []
    while num1!=0:
        num1_list.append(num1%10)
        num1 = num1//10
    num2_list = []
    while num2!=0:
        num2_list.append(num2%10)
        num2 = num2//10
    num2_list.sort()
    num1_list.sort()
    return (num1_list == num2_list)

def totient_eq(n, primes_list):
    divisors = []
    i = 0
    p = primes_list[i]
    phi = n
    while p <= n:
        if n % p == 0:
            divisors.append(p)
        i += 1
        n = n//p
        p = primes_list[i]
    for p in divisors:
        phi = phi//p
        phi *= p-1
    return phi
tmp1 = 2
tmp2 = 1

# print(totient_eq(87109, primes_list))
# for i in range(1, 10**7):
#     if(check_nums(i, totient_eq(i,primes_list))):
#         print(i, tmp, tmp2)
#         if(tmp2>i/totient_eq(i,primes_list)):
#             tmp = i
#             tmp2 = i/totient_eq(i,primes_list)
for i in range(2, len(primes_list)):
    #if(i%100==0):print(primes_list[i])
    for j in range(2, i):
        ii = primes_list[i]
        jj = primes_list[j]
        if(ii*jj<10**7):
            if(check_nums(ii*jj,(ii-1)*(jj-1)) and ii*jj/((ii-1)*(jj-1))<tmp1/tmp2):
                print(ii*jj, (ii-1)*(jj-1), ii, jj,ii*jj/((ii-1)*(jj-1)))
                tmp1 = ii*jj
                tmp2 = (ii-1)*(jj-1)
        else:
            break


