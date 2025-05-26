def palindrome(number) -> bool:
    number = str(number)
    for i in range(0,len(number)//2):
        if(number[i]!=number[len(number)-1-i]):
            return False
    return True

largest = 0
for i in range(700,1000):
    print(i)
    for j in range(i,1000):
        temp = i*j
        if(palindrome(temp) and temp>largest):
            largest = temp
            print(temp)
print(largest)