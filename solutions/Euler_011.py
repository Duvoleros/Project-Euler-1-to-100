import math

numbers = []
for i in range(0,20):
    numbers.append(input().split(' '))
    for j in range(0, 20):
        numbers[i][j] = int(numbers[i][j])
print(numbers)

largest_prod = 0
for i in range(0,20):
    for j in range(0,16):
        tmp = math.prod(numbers[i][j:j+4])
        if(tmp > largest_prod): largest_prod = tmp
        tmp = numbers[j][i] * numbers[j+1][i] * numbers[j+2][i] * numbers[j+3][i]
        if(tmp > largest_prod): largest_prod = tmp
for i in range(0,16):
    for j in range(0,16):
        tmp = numbers[j][i+3] * numbers[j+1][i+2] * numbers[j+2][i+1] * numbers[j+3][i]
        if(tmp > largest_prod): largest_prod = tmp
        tmp = numbers[j][i] * numbers[j+1][i+1] * numbers[j+2][i+2] * numbers[j+3][i+3]
        if(tmp > largest_prod): largest_prod = tmp
print(largest_prod)
