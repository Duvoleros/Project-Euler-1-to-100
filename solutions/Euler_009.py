def gcd_(a,b):
    while(a!=0 & b!=0):
        if(b>=a):
            b%=a
        else:
            a%=b
    return a

number_values = []
for i in range(0,1001):
    number_values.append([])

answer = 0

for i in range(2,36):
    for j in range(1,i):
        if(gcd_(j, i)!=1):
            continue
        a = i**2-j**2
        b = 2*i*j
        c = i**2+j**2
        if(1000 % (a+b+c) == 0):
            k = 1000//(a+b+c)
            print(a*k, b*k, c*k)
            print(k*k*k*a*b*c)
            break
    if (answer != 0):
        break
