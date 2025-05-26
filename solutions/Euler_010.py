rezult = 0
file = open("primes.txt", "r")
for i in file.readlines():
    if(int(i)>2e6): break
    rezult += int(i)
print(rezult)
