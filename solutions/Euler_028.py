sum = 1
counter = 1
for i in range (1,1001,2):
    for j in range(0,4):
        counter+=i
        counter+=1
        sum+=counter
print(sum)
