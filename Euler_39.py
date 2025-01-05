

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

for i in range(2,36):
    for j in range(1,i):
        if(gcd_(j, i)!=1):
            continue
        a = i**2-j**2
        b = 2*i*j
        c = i**2+j**2
        k = 1
        while(True):
            if((a+b+c)*k <= 1000):
                if(a<b):
                    a, b = b, a
                flag = True
                for value in number_values[(a+b+c)*k]:
                    if(value[0] == (a*k) and value[1] == (b*k)):
                        flag = False
                    break
                if(flag):
                    number_values[(a+b+c)*k].append((a*k,b*k,c*k))
            else:
                break
            k+=1
max = 0
for i in range(0,len(number_values)):
    print(i, len(number_values[i]))
    if(len(number_values[max])<len(number_values[i])):
        max = i
print(max," maximal ", number_values[max])
print(number_values[1000])