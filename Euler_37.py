prime_numbers = []

def check_prime(numb)->bool:
    if(numb == 1):
        return False
    index = 0
    sqrt = numb**0.5
    while(prime_numbers[index]<=sqrt):
        if(numb%prime_numbers[index]==0):
            return False
        index+=1
    return True

rezult = 0
file = open("primes.txt", "r")
for i in file.readlines():
    temp = int(i)
    if(temp<10**8):
        prime_numbers.append(int(i))

def left_check(num)->bool:
    temp_str = str(num)
    while(len(temp_str)>0):
        if(not check_prime(int(temp_str))):
            return False
        temp_str = temp_str[1:]
    return True

def right_check(num)->bool:
    while(num>0):
        if(not check_prime(num)):
            return False
        num = num//10
    return True

Truncatable = []
sum = 0
index = 4
while(len(Truncatable)<11):
    if(right_check(prime_numbers[index]) and left_check(prime_numbers[index]) ):
        Truncatable.append(prime_numbers[index])
        print(prime_numbers[index])
        sum+=prime_numbers[index]
    index+=1
print(sum)