import math
rez = 1 # 1^1 = 1 - only power of 1 that matters
print(1,"^",1, '=',1)
for i in range(1,40):
    temp = 1
    while(True):
        temp+=1
        power = temp**i
        if(math.ceil(math.log10(power))==i and temp!=10):
            print(temp,"^",i, '=',power)
            rez+=1
        if(math.ceil(math.log10(power))>i):
            break
    
print(rez)