original_array = []
size = 80
f = open("matrix.txt", "r")
for i in range(0,size):
    original_array.append([])
    original_array[-1] = [int(num) for num in f.readline().split(",")]
new_array = []
new_array.append([original_array[0][0]])
for j in range(1, size):
    new_array[0].append(original_array[i][j]+new_array[0][j-1])
print(new_array)
for i in range(1,size):
    new_array.append([original_array[i][0]+new_array[i-1][0]])
    for j in range(1, size):
        new_array[i].append(original_array[i][j]+min(new_array[i][j-1],new_array[i-1][j]))
print(new_array[-1][-1])#i don't know why this result is not correct
print(original_array[-1][-1])
second_array = original_array
for i in range(size-2,-1,-1):
    second_array[-1][i] += second_array[-1][i+1]
    second_array[i][size-1] += second_array[i+1][size-1]
print(second_array[-1])
for i in range(size-2,-1,-1):
    for j in range(size-2,-1,-1):
        second_array[i][j]+=min(second_array[i+1][j],second_array[i][j+1])
second_array[0][0]#correct result