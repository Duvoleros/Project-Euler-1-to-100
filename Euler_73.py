import math

rez = 0
for i in range(1, 12001):
    for j in range(0, i):
        if(j/i<1/2):
            if(j/i>1/3):
                if(math.gcd(i,j) == 1):
                    rez+=1
        else:
            break
print((rez))
