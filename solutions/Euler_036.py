def palindrome(string):
    for i in range(0,len(string)//2):
        if(string[i]!=string[len(string)-1-i]):
            return False
    return True   

def bin_palindrome(string):
    for i in range(0,len(string)//2-1):
        if(string[i+2]!=string[len(string)-1-i]):
            return False
    return True  

counter = 0
for i in range(0,1000000):
    if(palindrome(str(i))):
        if(bin_palindrome(str((bin)(i)))):
            counter+=i
            print(i)
print(counter)