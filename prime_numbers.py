prime_numbers = []
with open('primes.txt') as f:
    int_list = [int(num) for num in f.readlines()]
    prime_numbers = int_list
file = open("primes.txt", "a")
def check_prime(num):
    counter = 0
    sqrt = num**0.5
    while(prime_numbers[counter]<=sqrt):
        if(num%prime_numbers[counter]==0):
            return False
        counter+=1
    print(num)
    return True

for i in range(prime_numbers[-1]+2,10**15,2):
    if(check_prime(i)):
        prime_numbers.append(i)
        file.write("\n"+str(i))

file.write(prime_numbers)
        