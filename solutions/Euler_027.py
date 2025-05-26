prime_numbers = []
f = open("primes.txt", "r")
for i in f.readlines():
    if(len(prime_numbers)<120000):
        prime_numbers.append(int(i))



def check_prime(num):
    if(num <= 1):
        return False
    counter = 0
    sqrt = num**0.5
    while(prime_numbers[counter]<=sqrt):
        if(num%prime_numbers[counter]==0):
            return False
        counter+=1
    return True

max_sequence = 0
product = 1

for i in range(-1000, 1000+1):
    for j in range(1, 1000+1):
        n = 0
        while(check_prime(n**2+n*i+j)):
            n+=1
        if(n>max_sequence):
            product = i*j
            max_sequence = n
            print(n-1, i, j)
product