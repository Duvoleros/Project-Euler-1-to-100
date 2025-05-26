def check_prime(numb):
    index = 0
    sqrt = numb**0.5
    while(prime_numbers[index]<=sqrt):
        if(numb%prime_numbers[index]==0):
            return False
        index+=1
    return True

prime_numbers = []
file = open("primes.txt", "r")
for i in file.readlines():
    temp = int(i)
    if(temp<10**4):
        prime_numbers.append(temp)
file.close()
for i in range(9,10000,2):
    if(check_prime(i)):
        continue
    Flag = False
    for j in range(1,int((i/2)**0.5)+1):
        if(check_prime(i-2*j*j)):
            Flag = True
            break
        else:
            continue
    if(not Flag):
        print(i)
        break