rez = [1,3]
for i in range(8, 10**6+1):
    if(i % 7 == 0):
        if((3*i//7-1)*rez[1] > rez[0]*i):
            rez = [(3*i//7-1), i]
            print(rez)
    else:
        if((3*i//7)*rez[1] > rez[0]*i):
            rez = [(3*i//7-1), i]
            print(rez)    
