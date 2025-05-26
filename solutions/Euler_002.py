sum = 0
F1, F2 = 1, 1
while(F1 < 4e6):
    if(F1 % 2 == 0):
        sum += F1
    F1, F2 = F1+F2, F1
print(f'Sum is: {sum}.')
