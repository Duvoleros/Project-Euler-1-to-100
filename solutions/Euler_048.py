rez = 0
for i in range(1,1001):
    power = 1
    for j in range(0,i):
        power*=i
        power=power%(10**10)
    rez+=power
rez