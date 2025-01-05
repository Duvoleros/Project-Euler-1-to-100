prime_numbers = []
file = open("primes.txt", "r")
for i in range(1,340000):
    tmp = file.readline()
    if(int(tmp)<10**6):
        prime_numbers.append(int(tmp))
    else:
        break
def check_prime(num):
    counter = 0
    sqrt = num**0.5
    while(prime_numbers[counter]<=sqrt):
        if(num%prime_numbers[counter]==0):
            return False
        counter+=1
    print(num)
    return True

rez = 0
summ = 0
for i in range(0,len(prime_numbers)):
    for j in range(i+1,len(prime_numbers)):
       temp = sum(prime_numbers[i:j])
       if(temp>=10**6):
           break
       if(rez<j-i and check_prime(temp)):
           rez = j-i 
           summ = temp
           print(i,j,rez, temp)
summ