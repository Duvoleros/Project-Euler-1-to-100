file = open("primes.txt", "r")
rez = 1
for i in file.readlines():
    if(rez<10**6):
        rez *= int(i)
        print(i)
print(rez, rez/19)