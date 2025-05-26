original_array = []
second_array = []
size = 80
f = open("matrix.txt", "r")
for i in range(0,size):
    original_array.append([])
    second_array.append([])
    temp = f.readline().split(",")
    original_array[-1] = [int(num) for num in temp]
    second_array[-1] = [int(num) for num in temp]
    
def check_cell(i, j):
    print(i,j)
    if(i==0):
        second_array[i][j] = min(second_array[i][j],second_array[i+1][j]+original_array[i][j])
    elif(i==size-1):
        second_array[i][j] = min(second_array[i][j],second_array[i-1][j]+original_array[i][j])
    else:
        second_array[i][j] = min(second_array[i][j], second_array[i-1][j]+original_array[i][j], second_array[i+1][j]+original_array[i][j])
    return 1    

for i in range(size-2,0,-1):
    for j in range(size-1,-1,-1):
        second_array[j][i] += second_array[j][i+1]
    for j in range(size,-1,-1):
        for k in range(size-1, -1, -1):
            #print(i,k)
            if(k!=0):
                if(second_array[k][i]>second_array[k-1][i]+original_array[k][i]):
                    second_array[k][i] = second_array[k-1][i]+original_array[k][i]                
                    print("changed", k,i)
            if(k!=size-1):
                if(second_array[k][i]>second_array[k+1][i]+original_array[k][i]):
                    second_array[k][i] = second_array[k+1][i]+original_array[k][i]
                    print("changed", k, i)
            mini = 10**9
for j in range(size-1,-1,-1):
    second_array[j][0] = second_array[j][0] + second_array[j][1]
    if(second_array[j][0]<mini):
        mini = second_array[j][0]
mini