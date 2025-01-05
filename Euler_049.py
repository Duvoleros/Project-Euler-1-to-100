prime_numbers = []
file = open('primes20k.txt','r')
while True:
    prime_numbers.append(int(file.readline()))
    if(prime_numbers[-1]>10**4):
        break

def split(num):
    rez = []
    while(num>0):
        rez.append(num%10)
        num = num //10
    return rez

for i in range(len(prime_numbers)-1,-1,-1):
    if(prime_numbers[i]-3330 in prime_numbers and prime_numbers[i]-6660 in prime_numbers):
        temp = split(prime_numbers[i])
        temp.sort()
        temp2 = split(prime_numbers[i]-6660)
        temp2.sort()
        if(temp == temp2):
            print(prime_numbers[i]-6660,prime_numbers[i]-3330,prime_numbers[i])