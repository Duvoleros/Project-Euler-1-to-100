def palindrome(string):
    for i in range(0,len(string)//2):
        if(string[i]!=string[len(string)-1-i]):
            return False
    return True   
def reverse_(num):
    rez = 0
    while(num!=0):
        rez = rez*10+num%10
        num=num//10
    return rez
Lychrel = []
for i in range(12,10000):
    temp = i
    temp = temp + reverse_(temp)
    counter = 1
    while(counter<51 and (not palindrome(str(temp)))):
         temp = temp + reverse_(temp) 
         counter+=1
    if(counter == 51):
        Lychrel.append(i)
print(Lychrel)
print(len(Lychrel))
