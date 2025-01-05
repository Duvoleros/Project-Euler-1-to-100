prime_numbers = []
f = open("primes.txt", "r")
for i in f.readlines():
    if(len(prime_numbers)<1000):
        prime_numbers.append(int(i))


coins = set(prime_numbers)
n = 1000

parts = [1]+[0]*n
for c in coins:
    for i, x in enumerate(range(c, n+1)):
        parts[x] += parts[i]
for i, x in enumerate(parts):
    print(i,x)