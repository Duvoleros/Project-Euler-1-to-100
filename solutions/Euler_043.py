def checker(number):
    if((number%(10**3))%17 != 0):
        return False
    if((number%(10**4)//(10**1))%13 != 0):
        return False
    if((number%(10**5)//(10**2))%11 != 0):
        return False
    if((number%(10**6)//(10**3))%7 != 0):
        return False
    if((number%(10**7)//(10**4))%5 != 0):
        return False
    if((number%(10**8)//(10**5))%3 != 0):
        return False
    if((number%(10**9)//(10**6))%2 != 0):
        return False
    return True

def next_permutation(sequence):#taken from internet
	count = len(sequence)
	i = count
	while True:
		if i < 2:
			return False
		i -= 1
		if (sequence[i - 1] < sequence[i]):
			break
	j = count
	while j > i and not (sequence[i - 1] < sequence[j - 1]):
		j -= 1
	sequence[i - 1], sequence[j - 1] = sequence[j - 1], sequence[i - 1]
	j = count
	while i < j - 1:
		j -= 1
		sequence[i], sequence[j] = sequence[j], sequence[i]
		i += 1
	return sequence

counter = 0
number = ["1","0",'2','3','4','5','6','7','8','9']
while ("".join(number)!="9876543210"):
    if(checker(int("".join(number)))):
        counter+=int("".join(number))
        print("".join(number))
    number = next_permutation(number)
    
print(counter)