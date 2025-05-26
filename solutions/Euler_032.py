def get_perm(num, num2):
    num3 = num*num2
    tmp = []
    while(num!=0):
        tmp.append(str(num%10))
        num = num // 10
    while(num2!=0):
        tmp.append(str(num2%10))
        num2 = num2 // 10
    while(num3!=0):
        tmp.append(str(num3%10))
        num3 = num3 // 10
    tmp.sort()
    if("".join(tmp)!= "123456789"):
        return(False)
    return True
count = []
for i in range(1,1900):
    for j in range(i-1, 10000):
        if(i*j>120000):
            break
        if(get_perm(i,j)):
            count.append(i*j)
            print(i, j, i*j)
print(sum(set(count)))
count