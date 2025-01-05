def check_nums(num1, num2):
    num1_list = []
    while num1!=0:
        num1_list.append(num1%10)
        num1 = num1//10
    num2_list = []
    while num2!=0:
        num2_list.append(num2%10)
        num2 = num2//10
    num2_list.sort()
    num1_list.sort()
    return (num1_list == num2_list)

num = 1
while(True):
    num+=1
    if(not check_nums(num,2*num)):
        continue
    if(not check_nums(num,3*num)):
        continue
    if(not check_nums(num,4*num)):
        continue
    if(not check_nums(num,5*num)):
        continue
    if(not check_nums(num,6*num)):
        continue
    print(num)
    break