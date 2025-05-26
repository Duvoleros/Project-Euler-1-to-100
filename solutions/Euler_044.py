pentagonal = []
for i in range(0,3000):
    pentagonal.append(i*(3*i-1)//2)
    print(i, i*(3*i-1)//2,(-i)*(3*(-i)-1)//2)

def find():
    counter = 0
    counter2 =0
    for i in range(1, 10000):
        print(i)
        temp_index = i-1
        while(pentagonal[temp_index]>=pentagonal[i]/2):
            temp =[(pentagonal[i]-pentagonal[temp_index])]
            if(len(list(set(pentagonal).intersection(temp)))==1):
                counter+=1
                print(counter2, " full ",counter," pair found ",pentagonal[i]-pentagonal[temp_index], pentagonal[temp_index])
                temp = [(pentagonal[i]+pentagonal[temp_index])]
                if(len(list(set(pentagonal).intersection(temp)))==1):
                    print("FINALLY found ",pentagonal[i]-pentagonal[temp_index])
                    counter2+=1
                    return
                temp = [(2*pentagonal[i]-pentagonal[temp_index])]
                if(len(list(set(pentagonal).intersection(temp)))==1):
                    print("FINALLY found ",pentagonal[temp_index])
                    counter2+=1.
                    return
            temp_index-=1
    return
find()