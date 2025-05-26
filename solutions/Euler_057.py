numerator = 1
denominator = 1
rez = 0
for i in range(0, 1000):
    numerator, denominator = denominator*2 + numerator, denominator + numerator
    if(len((str)(numerator))-1 == len((str)(denominator))):
        rez+=1
        print(i)
        print(numerator,"/",denominator)
print(rez)