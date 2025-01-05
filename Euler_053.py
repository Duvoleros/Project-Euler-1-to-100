
def  c(n,k):
    rez = 1
    if(k<n-k):
        k = n-k
    for i in range(k+1,n+1):
        rez*=i
        rez = rez //(i-k)
    return rez

counter = 0
    
for i in range(23,101):
    for j in range(1,i):
        if(c(i,j)>10**6):
            counter+=1
            print(counter, i, j)

