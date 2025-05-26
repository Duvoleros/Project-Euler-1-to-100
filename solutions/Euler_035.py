def transform_(number):
    number1 = str(number//10)
    if(number1 == "0"):
        number1 = ""
    number2 = str(number%10)+number1
    return int(number2)
def check_prime(number):
    if(number//10==0):
        return True
    while number>0:
        if((number%10)%2==0):
            return False
        if((number%10)==5):
            return False
        number=number//10
    return True
prime_numbers = []
counter = 0
index = 0
summ = 0
file = open("primes200k.txt", "r")
for i in file.readlines():
    if(check_prime(int(i))):
        prime_numbers.append(int(i))
while(prime_numbers[index]<1000000):
    temp = transform_(prime_numbers[index])
    Flag = True
    while(temp!=prime_numbers[index]):
        if(len((list(set(prime_numbers).intersection([temp]))))==0):
            Flag = False
            break
        temp = transform_(temp)
    if(Flag):
        counter+=1
        print(prime_numbers[index])
    index+=1
    continue
print(counter)
    