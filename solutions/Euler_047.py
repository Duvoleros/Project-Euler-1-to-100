prime_numbers = []
rezult = 0
file = open("primes.txt", "r")
for i in file.readlines():
    temp = int(i)
    if(temp<(10**6)):
        prime_numbers.append(int(i))
file.close()
def num_of_primes(number):
    temp_numbers = number
    number_of_primes = 0
    index = 0
    while(prime_numbers[index]<=temp_numbers):
        if(temp_numbers % prime_numbers[index]==0):
            number_of_primes+=1
        while(not temp_numbers%prime_numbers[index]):
            temp_numbers=temp_numbers//prime_numbers[index]
        index+=1
    return number_of_primes
index_ = 2
t1, t2, t3, t4 = 0,0,0,0
while(not ((t1 == 4 and t4 == t1)and (t1 == t2 and t3 == t4))):
    t1,t2,t3,t4 = t2,t3,t4,num_of_primes(index_)
    print(index_,t4)
    index_+=1
print(index_-4)
    