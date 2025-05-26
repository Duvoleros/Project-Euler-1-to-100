def get_perm(num):
    count = 1
    num_m = num
    tmp = []
    while(num!=0):
        tmp.append(str(num%10))
        num = num // 10
    tmp.reverse()
    while(len(tmp)<9):
        count+=1
        num2 = num_m * count
        tmp2 = []
        while(num2!=0):
            tmp2.append(str(num2%10))
            num2 = num2 // 10
        tmp2.reverse()
        tmp = tmp+tmp2
    rez = "".join(tmp)      
    tmp.sort()
    if("".join(tmp)!= "123456789"):
        return(False)
    print(rez)
    return True
count = []
for i in range(1,10000):
    if(get_perm(i)):
        print(i)
        count.append(i)
print(sum(set(count)))
count