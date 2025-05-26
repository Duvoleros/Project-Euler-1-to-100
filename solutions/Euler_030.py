lister = []
power5 = []
for i in range (0,11):
    power5.append(i**5)
for i in range (2,300000):
    num = i
    cout = 0
    while(num!=0):
        cout+=power5[num%10]
        num = num//10
    if(cout == i):
        lister.append(cout)
        print(i, " accepted!!!")
summ =0
for i in lister:
    summ+=i
print(summ)