cube_set = dict()
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

def change_to(num1):
    num1_list = []
    while num1!=0:
        num1_list.append(num1%10)
        num1 = num1//10
    (num1_list).sort(reverse=True)
    rez = 0
    for i in num1_list:
        rez = rez*10+i
    return rez

for i in range(10000,1, -1):
    tmp = change_to(i**3)
    if(tmp in cube_set):
        if(cube_set[tmp]==4):
            print(i**3)
        cube_set[tmp]+=1
    else:
        cube_set[tmp]=1