
def  c(n,k):
    rez = 1
    if(k<n-k):
        k = n-k
    for i in range(k+1,n+1):
        rez*=i
        rez = rez //(i-k)
    return rez

counter = 0
c_n = [-1]    
for i in range(1,201):
    c_n.append(c(i+1,2))
counter = 2*10**6
rez = 0
for i in range(1,201):
    for j in range(i, 201):
        tmp = c_n[i]*c_n[j]
        print(i, j, tmp)
        if(abs(tmp-2*10**6)<counter):
            counter = abs(tmp-2*10**6)
            rez = i*j
            print(rez)
rez