len = input().split(" ")
data = []
iter = 0
number = 3100#15 for problem 18
for i in range(1,number+1):
    temp = []
    for j in range(iter,iter+i):
        temp.append(len[j])
    iter = iter+i
    data.append(temp)
print(data)
for i in range(0,number):
    for j in range(0,number-1-i):
        data[number-2-i][j] = int(data[number-2-i][j])+max(int(data[number-1-i][j+1]),int(data[number-1-i][j]))
    print(i)
print(data[0][0])
