prime_list = [2,3,5,7]

def check_prime(num):
    for i in range(0, len(prime_list)):
        if(prime_list[i]>num**0.5):
            break
        if(num % prime_list[i]==0):
            return False
    return True

counter = 11
while(len(prime_list)<10005):
    if(check_prime(counter)):
        prime_list.append(counter)
        print(counter)
    counter+=2
print(prime_list[10000], "required prime")