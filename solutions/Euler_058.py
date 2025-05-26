import random

import math

def is_prime(n):

    if n <= 1:
        return False

    if n <= 3:
        return True

    if n % 2 == 0 or n % 3 == 0:
        return False

    for i in range(5, int(math.sqrt(n) + 1), 6):
        if n % i == 0 or n % (i + 2) == 0:
            return False

    return True


def jacobiSymbol(a, n):
    print(a,n)
    if (n == 1):
        return 1
    elif a == 0:
        return 0
    elif a % 2 == 0:
        return jacobiSymbol(2, n) * jacobiSymbol(a // 2, n)
    elif a % n == 0:
        return 0
    elif a % 4 == 3 and n % 4 == 3:
        return -jacobiSymbol(n, a)
    else:
        return jacobiSymbol(n, a)
    
def solovay_strassen(n, k):
    if n <= 3:
        if n == 1:
            return False
        return True

    for i in range(0,k):
        a = random.randint(2, n - 2)
        x = pow(a, n - 1, n)
        if x != 1:
            return False

        if not (jacobiSymbol(a, n) % n == x % n):
            return False

    return True

prime_numbers = []

def gcd(x, y):
    while(y):
        x, y = y, x % y
    return x


def check_prime(numb)->bool:
    if(numb == 1):
        return False
    index = 0
    sqrt = numb**0.5
    while(prime_numbers[index][0]<=sqrt):
        if(numb%prime_numbers[index][0]==0):
            return False
        index+=1
    return True

def check_prime2(numb)->bool:#Solovay–Strassen primality test
    for i in range(0, 10):
        a = int(random.random()*numb)
        if(gcd(a,numb)>1):
            return False
        if((a**((numb-1)/2))==jacobiSymbol(a,numb)%numb):
            return False
    return True

def is_prime(n): 
    rt = math.sqrt(n) 
    for i in range(2, int(rt) + 1): 
        if n % i == 0: 
            return False 
    return True
# rezult = 0
# file = open("primes.txt", "r")
# for i in file.readlines():    
#     prime_numbers.append(int(i))

num_of_primes = 0
num_of_diagonal = 1
prime_index = 0
counter = 1
for i in range (1,30001,2):
    for j in range(0,4):
        counter+=i
        counter+=1
        num_of_diagonal+=1
        # while(counter > prime_numbers[prime_index]):
        #     prime_index+=1
        # if(counter == prime_numbers[prime_index]):
        #     num_of_primes+=1
        #     prime_index+=1
        if(j!=3):
            if(is_prime(counter)):
                num_of_primes+=1
                print(counter)
    if(num_of_primes!=0):
        print(i,counter,round(num_of_primes/num_of_diagonal,5))
        if(num_of_primes/num_of_diagonal<0.1):
            print(i+2)
            break
print()
